#!/bin/bash

# Text converter Script
# brief  A conversion script that will take the text from a file and convert all characters to upper or lower case.  
# author Luke E. Tatro
# Text converter Script
# date 10/14/2020

#brief   A function that will alert the user of incorect usage of the commands and display the correct usage
usage()
{
  echo "Incorrect usage"
  echo "$0 usage: [-f input filed] [-c U(pper) or L(lower)" 
  exit 1
}

#brief   A while loop that will generate the options of -f and -c. The loop will run through the user input
#        to check for correct usage. If correct usage is used and the file entered is an existing file 
#        the user will be informed and the conversion to uppercase or lower case will occur. 

while getopts ":f:c:" options;  #whatever gets typed into gets stuffed into the variable options 
do 
  case "${options}" in 
    f) #this comes from the top of the while loop
      f=${OPTARG}

#brief   The below code will check to see if the file is existing or not. It it does not exist usage will be called

      if [ -e "$OPTARG" ]; then
	echo "${OPTARG} is an existing file"
      else
        echo "${OPTARG} is not an existing file" 
	usage
      fi 
      #to do if file is here. if not usage so 
      #this we will do outselves. we need to put in the usage statemnt. 

#brief   the below code will check that the correct commands of U or L were used 
    
    ;;
    c)
      c=${OPTARG}
      if [[ ${c} == "U" || ${c} == "L" ]]; then 
        echo "${f} - ${c}"
      else 
        usage 
      fi
    ;;
    *) #default statement 
    usage
    ;;
  esac

done

#brief   the below code will convert the text to either upper case or lower case 

while read line
do
  if [ ${c} == "U" ]; then 
    echo $line | tr [:lower:] [:upper:] #convert lower case to uper case 
  else
    echo $line | tr [:upper:] [:lower:]
  fi 
done <$f

#conversion logic here
exit 0
