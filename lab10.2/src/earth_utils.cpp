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

#include "earth_utils.h"
#include <sstream> 
#include <fstream> 
#include <iostream> 

 
 
int processCSV(std::ifstream& inFile, std::string kmlFileName)
{
    std::string strCountry, strCapital, strLat, strLong; 
    std::string strLine; 
    std::string name; 
    int recordCount{}; 

    if(inFile)
    {
        getline(inFile, strLine); 

        std::ofstream outFile; 

        outFile.open(kmlFileName); 
        outFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl; 
        outFile << "<kml xmlns=\"http://www.opengis.net/kml/2.2\">" << std::endl; 
        outFile << "<Document>" << std::endl; 
        while (getline(inFile, strLine))
        {
            std::stringstream s_stream(strLine); 
            std::getline(s_stream, strCountry, ','); 
            std::getline(s_stream, strCapital, ',');
            std::getline(s_stream, strLat, ',');
            std::getline(s_stream, strLong, ',');

            name = strCapital + ", " + strCountry; 
            std::cout << strCountry << "~" << strCapital << "~" << strLat << "~" << strLong << std::endl; 
            
            writePlacemark(outFile, name, strLat, strLong); 
            recordCount++; 

        }

        outFile << "</Document>" << std::endl; 
        outFile << "</kml>" << std::endl; 

        outFile.close(); 
    }

    return recordCount;  

}

void writePlacemark(std::ofstream& kmlFile, std::string name, std::string latitude, std::string longitude)
{
    kmlFile << "<Placemark>" << std::endl; 
    kmlFile << "<name>" << name << "</name>" << std::endl; 
    kmlFile << "<Point><coordinates>" << longitude << "," << latitude << "</coordinates></Point>" << std::endl; 
    kmlFile << "</Placemark>" << std:: endl; 
}
