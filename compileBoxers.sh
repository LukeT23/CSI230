#!/bin/bash

# CompileBoxers Script
# brief  Reads in text file of basic boxer information and runs it throug the pal_driver program 
# to create text file of advanced information and then it emails it to my gmail along with the logging information.   
# author Luke E. Tatro
# CompileBoxers Script
# date 12/8/2020 


#brief   funtion to make sure the user is the root user
checkRoot()
{
  userid=$(id -u)
  echo "The current user is: $(whoami)"

  if [ "$userid" -eq 0 ]; then
    echo "You are logged in as root" 
  else 
    echo "$(whoami) is not root"
    echo "You must be root to execute this program" >&2
    exit 1 
  fi

}


#MAIN

PROGNAME="$basename"$0")" 

checkRoot

#brief   checks if file exists and runs it through pal_driver program 

if [ -e "$1" ]; then 
  pal_driver -k "$1" -l /home/luketatro/CSI230/GitHubRepository/CSI230/FINALPROJECT/mylogfile.txt 

#brief   email myslef the new boxer info text and the logging information  
        userEmail=lukeetatro@gmail.com 
	hashPass= ###ADD IN HASH PASS 
        #echo $user
        echo $userEmail
	
        email_body=$(cat /home/luketatro/CSI230/GitHubRepository/CSI230/FINALPROJECT/mylogfile.txt) 
        email_subject="Boxer information from $1" 
        echo -e "${email_body}" | s-nail -S smtp-use-starttls -S ssl-verify=ignore -S smtp-auth=login -S smtp="smtp.gmail.com:587" -S smtp-auth-user="lukeetatro@gmail.com" -S smtp-auth-password="${hashPass}" -r "lukeetatro@gmail.com" -a boxers_info.txt -s "${email_subject}" -. "${userEmail}"

 #done
else 
  echo "File ${1} does not exist. Please use a different file." >&2 
fi 


