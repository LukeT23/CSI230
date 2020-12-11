/**
* @file utils.h
* @brief  Linux Final Project 
* handles declarations for functions used to process Boxer class object data 
* @author Luke E. Tatro 
* @Linux Final Project 
* @date 12/1/2020
* 
*/


#ifndef UTILS_H
#define UTILS_H

#include "boxers.h"
#include "boost/date_time/gregorian/gregorian.hpp" //EXTERNAL LIBRARY 
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip> 



using namespace std; 

//FUNCTION HEADERS 

/**
* @brief Determines the current year using the boost/date_time library
* @date 12/8/2020
* @return returns an int 
*/

int getCurrentYear(); 

/**
* @brief Determines the current month using the boost/date_time library
* @date 12/8/2020
* @return returns an int 
*/

int getCurrentMonth(); 

/**
* @brief Opens a text file and stores the data into a vector of boxers 
* @date 12/3/2020
* @return returns an int indicating how many records were recorded 
* @param vector<Boxer*>& boxers: used to store the Boxer class objects 
* @param Boxer* A pointer used to dynamically created Boxer objects 
* @param fileName the input file to read data from 
*/

int inputBoxers(vector<Boxer*>& boxers, Boxer* boxer, string fileName);

/**
* @brief Opens a text file and outputs the data stored in a vector of boxers 
* @date 12/3/2020
* @param vector<Boxer*>& boxers: where the Boxer class objects info is stored 
* @param Boxer* A pointer used access the objects 
* @param fileName the output file to send data too. 
*/

void outputBoxers(vector<Boxer*> const& boxers, string fileName); 

/**
* @brief Destroys a dynamically allocated vector of Boxers
* @date 12/3/2020
* @param vector<Boxer*>& boxers: The vector to be destroyed 
*/

void nukeVector(vector<Boxer*>& boxers); 

/**
* @brief Used to verify that input from the file is correct 
* @date 12/3/2020
* @return returns a bool if correct input has been entered. 
* @param ints: used to set the minumum and maximum amounts and input should be and to take in the input. 
* @param string name: Takes the boxers name to be printed if invalid input is entered 
* @param string message: A message to tell the user what data input failed 
*/

bool inputError(int min, int max, int input, string name, string message); 

/**
* @brief Resizes a boxers name to be no more than 10 characters including blank space buffers 
* @date 12/3/2020
* @param string& name: Takes in the boxers name by reference to permanently change it.
*/

void resizeName(string& name);

/**
* @brief Takes in current date and boxers birth date to calculate their age. 
* @date 12/3/2020
* @return returns an int indicating the boxer's age 
* @param ints: Takes in boxers birth month and year and compares to the current month and year 
*/

int calcAge(int birthMonth, int birthYear, int year, int month);

/**
* @brief Used to create an over head display when printing boxer info 
* @date 12/3/2020
* @return returns a string as the over head display 
*/

string boxerDisplay(); 

/**
* @brief Takes in the Boxer Vector and determines what tournaments each boxer is eligible for
* @date 12/3/2020
* @param vector<Boxer*> const& boxers: The vector of Boxers 
* @param ofstream& outFile used so that the boxer eligibilty can be printed to the outFile 
*/

void tournaments(vector<Boxer*> const& boxers, ofstream& outFile);

/**
* @brief Takes in the Boxer object via pointer and determines eligibity for a specific tournament 
* @date 12/3/2020
* @param Boxer* boxer: A pointer used to take an object from the Boxer Vector 
* @param ints: Used to input tournament dates along with min and max age of competitors 
* @param string message: Used to output the name of the tournmanet 
* @param ofstream& outFile used so that the boxer eligibilty can be printed to the outFile 
*/

void  tournamentEligible(Boxer* boxer, int tourYear, int tourMonth, int minAge, int maxAge, string message, ofstream& outFile);

/**
* @brief Determines the date of a tournment 
* @date 12/3/2020
* @return Returns an int that indicated the year the tournament will take place 
* @param int months: Takes in the tournament month a current month and determines if the 
* tournament will happen in the current year or next year
* @param int year: Used to take in current year and is incremented by 1 if tournament will happen next year
*/

int tourYear(int tourMonth, int currentMonth, int numYear); 

#endif