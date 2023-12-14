#!/bin/bash
# this is for add from 1 to 100
num=1
sum=0
while [ $num -le 100 ];do
	sum=$[sum+num]
	let num++
done
echo $sum
