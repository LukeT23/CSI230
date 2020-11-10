/**
* @file earth_utils.h
* @brief  Lecture 10.2 Lab
* handles the parsing a lat/long csv file and conversion of that file to kml format
* @author Luke E. Tatro 
* @credit Bilbo Baggins
* @assignment Lecture 10.2
* @date 11/8/2020
* @credits
* 
*/

#ifndef EARTH_UTILS_H
#define EARTH_UTILS_H 

#include <string> 
#include <fstream> 

/**
* @brief process a country csv file 
* @date 11/8/2020
* @return returns the number of records processed  
* @param infFile ifstream to an opened and valibated csv file 
* @param kmlFileName std:string containing hte name of hte kml file you wish to produce 
* @param logFile ofstream reference, validation of this file is epxected
*/

int processCSV(std::ifstream& inFile, std::string kmlFileName); 

void writePlacemark(std::ofstream& kmlFile, std::string name, std::string latitude, std::string longitude, std::string elevation="0"); 
//this won't return anything because it will only write one record. 
//Notice that elevation="0" is not present in processCSV. This is needed for a kml file though. 


#endif 
