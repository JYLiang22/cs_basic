#!/bin/bash
# this is for continue
# by author eason 2023.09.22
N=0
while [ $N -lt 5 ];do
	let N++
	if [ $N -eq 3 ];then
		continue
	fi
	echo $N
done
