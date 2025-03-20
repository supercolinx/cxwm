#!/bin/sh

#ROOT_PATH=$(dirname $0)
ROOT_PATH=$(pwd)

main()
{
	./build/wm &
	WM_PID=$(echo $!) # get last pid

	while true
	do
		sleep 3
		ps --pid ${WM_PID}
		if [ $? != 0 ]; then
			killall start_wm.sh
			sh ${ROOT_PATH}/scripts/start_wm.sh &
			break
		fi
	done
	exit 0
}

main

unset ROOT_PATH
unset WM_PID
