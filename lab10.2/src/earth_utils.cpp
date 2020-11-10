/**
* @file earth_utils.h
* @brief  Lecture 10.2 Lab
* Implements google earth file handling utilities 
* @author Luke E. Tatro 
* @credit Bilbo Baggins
* @assignment Lecture 10.2
* @date 11/8/2020
* @credits
* 
*/

#include "earth_utils.hpp"
#include <sstream> //will be used for line parsing 
#include <iostream> 

int processCSV(std::ifstream& inFile, std::string kmlFileName)
{
    std::string strCountry, strCapital, strLat, strLong; 
    std::string strLine; //represents the entire line in a csv file 
    int recordCount{}; 

    //if infile doesn't exist, bail returning records written
    // if does exists
    //create the kmlFile
    //write out the header 
    //read each line in the inFile, skipping the first one 
    if(inFile)
    {
        getline(inFile, strLine); 
        //std::cout << strLine << std::endl; //debugging only 
        ///will later put this in a loop to see if recrods are being read ok
        while (getline(inFile, strLine))
        {
            //std::cout << strLine << std::endl;
            std::stringstream s_stream(strLine); 
            std::getline(s_stream, strCountry, ','); //grabs the line we are on with s_stream, 
                                                    //all the info up to the comma and puts it in country. 
            
            //std::cout << strCountry << std::endl; 
            std::getline(s_stream, strCapital, ',');
            std::cout << strCountry << "~" << strCapital << std::endl; 

            //I need to get lattitude and longitude by implementing strlat strlong 
            //and I need to increment my record count  
        }
    }

    //call the WritePlacemark function to create a record 
    //increment the count of recrods
    //write any footer out 
    return recordCount;  

}