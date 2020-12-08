/**
* @file pal.cpp
* @brief  Linux Final Project 
* implements functions pal.h 
* @author Luke E. Tatro 
* @Linux Final Project 
* @date 12/1/2020
* @credit Devin Paden 
*/

#include "pal.h"
#include <iostream>
#include <string>
#include <ctime> 
#include <unistd.h>

using  namespace std; 

bool log(string msg, string programName, ofstream& logFile)
{
	bool retVal = false; 
	string strTime; 

	//get the time 
	time_t logTime = time(0); 
	strTime = ctime(&logTime); 

	int timeSize = strTime.size(); 

	if (timeSize)
	{
		strTime[timeSize-1] = ' '; 
	}

	//get program name take the info and headers from main and put them here

	// get the pid take the info and headers from main and put them here
	pid_t pid = getpid(); 
	//get the hostname (I haven't shown you this) used a function called gethostname 
	//get host name takes a char pointer and a length of bits. 
	string strHostName; 
	char hName[256];
	gethostname(hName, 10); 

	strHostName = hName; 
	
	if (logFile)
	{
		
		//write the log
		// add pid after the program name so that it looks like:    program[pid]
		logFile << strTime << strHostName << " " << programName << "[" << pid << "]: " << msg << std::endl; 

		retVal = true; 
	}

	return retVal; 
}