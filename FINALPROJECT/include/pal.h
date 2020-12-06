
/**
* @file pal.h 
* @brief  Linux Final Project 
* handles declarations for functions used to to process class object data 
* @author Luke E. Tatro 
* @Linux Final Project 
* @date 12/1/2020
* 
*/

#ifndef PAL_HPP
#define PAL_HPP

#include "boxers.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std; 

/**
* @brief creates a discrete syslog message
* @date 11/8/2020
* @return returns a boolean indicating the message was written ok 
* @param msg std:string countaining syslog message
* @param programName std:stringcontaining the program name
* @param logFile ofstream reference, validation of this file is epxected 
*/


bool log(std::string msg, std::string programName, std::ofstream& logFile); 

int inputBoxers(vector<Boxer*>& boxers, Boxer* boxer, string fileName);

void outputBoxers(vector<Boxer*> const& boxers, string fileName); 

void nukeVector(vector<Boxer*>& boxers); 

bool inputError(int min, int max, int input, string name, string message); 

void resizeName(string& name);

int calcAge(int birthMonth, int birthYear, int year, int month);

string boxerDisplay(); 

int rangeBuffer(int num1, int num2, int size); 

int setBuffer(int age, int size); 

void tournaments(vector<Boxer*> const& boxers, ofstream& outFile);

void  tournamentEligible(Boxer* boxer, int tourYear, int tourMonth, int minAge, int maxAge, string message, ofstream& outFile);

int tourYear(int num1, int num2, int numYear); 

#endif 