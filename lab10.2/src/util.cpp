/**
* @file logger.cpp
* @brief  Lecture 10.2 Lab
* handles the delcaration of all logging functionality 
* @author Luke E. Tatro 
* @credit Bilbo Baggins
* @assignment Lecture 10.2
* @date 11/8/2020
* @credits
* 
*/


#include <iostream>
#include <string>
#include <ctime> 
#include <unistd.h>
#include "util.hpp"


bool log(std::string msg, std::string programName, std::ofstream& logFile)
{
	std::string strTime; 

	//get the time 
	time_t logTime = time(0); 
	strTime = ctime(&logTime); 

	int timeSize = strTime.size(); 

	if (timeSize)
	{
		strTime[timeSize-1] = ' '; 
	}

	//get program name take the info and headers from main and put them here

	//std::string strProgramName; ADDED PROGNAME AS A PARAM TO THE FUNCTION

	// get the pid take the info and headers from main and put them here
	pid_t pid = getpid(); 
	//get the hostname (I haven't shown you this) used a function called gethostname 
	//get host name takes a char pointer and a length of bits. 
	std::string strHostName; 
	char* name;
	gethostname(name, 10); 
	
	if (logFile)
	{
		//write the log
		// add pid after the program name so that it looks like:    program[pid]
		//log file << strTime << strHostname << " " << strProgramName << "[" << pid << "]: " << msg << std::endl; 

		return true; 
	}
}