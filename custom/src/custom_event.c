/**
 * @file	custom_event.c
 * @author	Colin X
 * @date	Fri Jun 19 00:01:14 2026
 * @description:
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/epoll.h>

#include "custom_event.h"

#define CUSTOM_EVENT_FIFO	"/tmp/supercolinx"
#define CUSTOM_EVENT_MAX	32

struct custom_event {
	int fd;
	int epfd;
	custom_event_cb_t cb;
};

static struct custom_event s_event = {-1, -1};

int custom_event_init(void)
{
	(void)unlink(CUSTOM_EVENT_FIFO);

	if (mkfifo(CUSTOM_EVENT_FIFO, 0644) == -1) {
		fprintf(stderr, "%m\n");
		return -1;
	}

	s_event.fd = open(CUSTOM_EVENT_FIFO, O_RDWR | O_NONBLOCK);
	if (s_event.fd == -1)
		goto ERROR;

	s_event.epfd = epoll_create1(EPOLL_CLOEXEC);
	if (s_event.epfd == -1)
		goto ERROR;

	struct epoll_event ev;
	ev.events = EPOLLIN | EPOLLET;
	ev.data.fd = s_event.fd;
	if (epoll_ctl(s_event.epfd, EPOLL_CTL_ADD, s_event.fd, &ev) == -1)
		goto ERROR;

	return 0;
ERROR:
	fprintf(stderr, "%m\n");
	custom_event_deinit();
	return -1;
}

void custom_event_deinit(void)
{
	if (s_event.epfd) {
		close(s_event.epfd);
		s_event.epfd = -1;
	}

	if (s_event.fd != -1) {
		close(s_event.fd);
		s_event.fd = -1;
	}

	(void)unlink(CUSTOM_EVENT_FIFO);
}

void custom_event_set_callback(custom_event_cb_t cb)
{
	s_event.cb = cb;
}

void custom_event_dequeue(int timeout)
{
	struct epoll_event evs[CUSTOM_EVENT_MAX];

	int n = epoll_wait(s_event.epfd, evs, CUSTOM_EVENT_MAX, timeout);
	if (n == 0) {
		return;
	} else if (n == -1) {
		if (errno == EINTR)
			fprintf(stderr, "%m\n");
		return;
	}

	custom_event_t events[CUSTOM_EVENT_MAX];
	ssize_t size = 0;
	for (int i = 0; i < n; ++i) {
		if (evs[i].data.fd != s_event.fd)
			continue;
		while ((size = read(s_event.fd, events, sizeof(events))) > 0)
		{
			if (s_event.cb)
				s_event.cb(events, size/sizeof(custom_event_t));
		}
	}
}

int custom_event_enqueue(const custom_event_t event)
{
	return write(s_event.fd, &event, sizeof(custom_event_t)) == -1 ? -1 : 0;
}
