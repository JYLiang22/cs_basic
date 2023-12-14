#!/bin/bash
# this is for checking break
# by author eason 2023.09.23
N=0
while True;do
	let N++
	if [ $N -eq 5 ];then
		break
	fi
	echo "$N"
done
