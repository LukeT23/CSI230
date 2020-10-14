#!/bin/bash
# Host name lookup Script
# brief  A script that will look up hostnames in a specified file and print the host names ip addresses  
# author Luke E. Tatro
# Host name look up Script
# date 10/14/2020

#brief   A positional parameter that will read in a text file entered by the user

PROGNAME="$(basename "$0")"

#brief   An if statement to check if the file is an existing file or not
#        If it is a while loop will grap the host names and find their ip addresses

if [ -e "$1" ]; then 
  for h in $(cat "$1"); 
  do 
   out=$(host -W1 -t A $h)  #this will grab all of ip addresses of the hosts found in the file 
   if [ $? -eq 0 ]; then
     ip=$(echo $out | cut -d " " -f 4) #echo pushes the info put into out through hte pipe to cut which will find the ip a>
     echo $h - $ip #this will print host name with the ip address
   else
     echo "${h} does not have a DNS record" 
   fi
  done 
else
  echo "File does not exist" >&2
  exit 1
fi 
