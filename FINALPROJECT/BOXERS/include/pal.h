
/**
* @file pal.h 
* @brief  Linux Final Project 
* handles declaration for log function
* @author Luke E. Tatro 
* @Linux Final Project 
* @date 12/1/2020
* 
*/

#ifndef PAL_HPP
#define PAL_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <ctime> 
#include <unistd.h>

using namespace std; 

/**
* @brief creates a discrete syslog message
* @date 12/3/2020
* @return returns a boolean indicating the message was written ok 
* @param msg std:string countaining syslog message
* @param programName std:stringcontaining the program name
* @param logFile ofstream reference, validation of this file is epxected 
*/


bool log(string msg, string programName, ofstream& logFile); 

#endif 