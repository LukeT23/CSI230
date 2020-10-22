#!/bin/bash

usage()
{
 echo "program is running"  
}

checkRoot()
{
  userid=$(id -u)
  echo "The current user is: $(whoami)"

  if [ "$userid" -eq 0 ]; then
    echo "You are logged in as root" 
  else 
    echo "$(whoami) is not root"
    echo "You must be root to execute this program" 
    exit 1 
  fi

}




#MAIN

PROGNAME="$basename"$0")" 

checkRoot

if [ -e "$1" ]; then 
 for user in $(cat "$1"| cut -d"@" -f 1); 
  do echo  $user;  
     deluser $user;
     $(rm -rf /home/$user/); 
     delgroup $user;  
 done
else 
  echo "Did not work" 
fi 


#for user in $(cat /home/luketatro/bin/emails.txt | cut -d"@" -f 1); do echo  $user; done

echo " " 
echo " " 
usage

