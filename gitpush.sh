#!/bin/bash
func(){
    git add .
    read -p "input your choice:1|2|3   1 daily update 2 need extre msg 3 exit:  " char
    case $char in
    1)
        git commit -m "daily update"
        git push
        ;;
    2)
        read -p "input your own commit:  " msg
        git commit -m "$msg"
        git push
        ;;
    3)
        git restore --stage .
        exit
        ;;
*)
esac
}

func