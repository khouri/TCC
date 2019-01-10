#! /bin/bash
clear

printf "This informationprovided by mysystem.sh. Program starts now.\n"

printf "Hello, $USER.\n\n"


printf "Today's date is 'date', this is week 'date+"%V"'\n\n"


printf "These users are currently conected:\n"
w | cut -d " " -f 1 - | grep -v USER |sort -u
printf "\n"


printf "This is 'uname -s' running on a 'uname -m' processor\n\n"


printf "This is the uptime information:\n"
uptime


printf "That's all folks!\n"
