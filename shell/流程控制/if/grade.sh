#!/bin/bash
# this is for checking grade
# by author eason 2023.09.21
grade=$1
if [ $grade -gt 90 ];then
	echo "very good"
elif [ $grade -gt 70 ];then
	echo "good"
elif [ $grade -gt 60 ];then
	echo "pass"
else
	echo "no pass"
fi
