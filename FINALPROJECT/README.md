# LINUX FINAL PROJECT 
Project overview
* The purpose of this project is to take in basic information about a boxer and output more detailed information into a text document that can be emailed to the boxer's trainer 

BOXER functionality 
* The program takes in a file and uses the information to create Boxer class objects which are dynamically allocated into a vector of Boxers. 
* The program verifies that the file exists before creating objects and then outputs the detailed infromation into a text file called boxers_info.txt 
* The detailed information includes the boxer's gloves size, weight divisions in USA and CA, and round length in USA and CA as well as what tournaments they are eligible for. 

Shared Libraries 
* The program utilizes shared libraries. One is the pal library which handles logging functionality to log information the user that has run the program and how many items were logged 
* It also uses an external boost library called Boost::Date which is used to determine the current date. 

compileBoxers.sh
* This script is used to verify the user using the program is root and then uses the BOXER program to create the boxers_info.txt file. 
* Once completed it emails the boxers_info.txt file is created it is emailed to the trainer along with the logging information. 
