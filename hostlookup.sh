#!/bin/bash
#comments go here

PROGNAME="$(basename "$0")"

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
