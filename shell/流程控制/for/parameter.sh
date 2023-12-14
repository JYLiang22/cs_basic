#!/bin/bash
# this is for output parameters
# by author eason 2023.09.22
num1=$1
num2=$2
num3=$3
for para in $*;do
	echo "$0 have $para"
done
echo "para num is $#, is $*"
