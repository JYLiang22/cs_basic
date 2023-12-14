#!/bin/bash
# this is for comparing two nums 
# by author eason 2023.09.21
num1=$1
num2=$2
if [ $num1 -gt $num2 ];then
	echo "$num1 is greater than $num2"
elif [ $num1 -lt $num2 ];then
	echo "$num1 is litter than $num2"
else
	echo "$num1 is equal to $num2"
fi
