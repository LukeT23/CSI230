
/**
* @file logger.h
* @brief  Lecture 10.2 Lab
* handles the delcaration of all logging functionality 
* @author Luke E. Tatro 
* @credit Bilbo Baggins
* @assignment Lecture 10.2
* @date 11/8/2020
* @credits
* 
*/

#ifndef UTIL_HPP
#define UTIL_HPP
#include <string>
#include <fstream>
#include <sstream>

/**
* @brief creates a discrete syslog message
* @date 11/8/2020
* @return returns a boolean indicating the message was written ok 
* @param msg std:string countaining syslog message
* @param programName std:stringcontaining the program name
* @param logFile ofstream reference, validation of this file is epxected 
*/


bool log(std::string msg, std::string programName, std::ofstream& logFile); 

#endif 