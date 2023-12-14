#!/bin/bash
func(){
	var=$((1+1))
	echo "this is a function"
	return $var
}
func
echo $?
