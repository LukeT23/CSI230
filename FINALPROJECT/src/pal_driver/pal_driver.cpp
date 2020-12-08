/**
* @file boxers.cpp
* @brief  Linux Final Project 
* Runs the program taking in a file name and outputting it into a new file 
* @author Luke E. Tatro
* @credit Devin Paden  
* @Linux Final Project 
* @date 12/1/2020
* 
*/

#include "pal.h"
#include "boxers.h"
#include "boost/date_time/gregorian/gregorian.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip> 
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>


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

string name;
int genderInt; 
int birthMonth;
int birthYear;
int weight;
int bouts;

const int MAX_CHAR = 10;
const int GLOBAL_MIN = 0;
const int MIN_BOXER_AGE = 8;
const int MAX_BOXER_AGE = 50;

int currentYear = getCurrentYear(); 
int currentMonth = getCurrentMonth(); 
int const MONTHS_IN_YEAR = 12;

int main(int argc, char* argv[])
{

    int opt{}; 
    int recordCount = 0; 
    bool boxerFlag{false}; 
    bool logFlag{false}; 
    string logValue; 
    string boxerFile; 
    bool optErr = true; 

    string coraName = "Cora"; 
    resizeName(coraName); 
    vector<Boxer*> gymBoxers;
    Boxer* boxer = new Boxer(coraName, Gender::FEMALE, 13, 4, 2007, 115, 8); 
    gymBoxers.push_back(boxer);


    while((opt = getopt(argc, argv, "k:l:")) != EOF)
    {
        switch(opt)
        {
            case 'k': 
                    boxerFlag = true; 
                    boxerFile = optarg; 
                    break; 

            case 'l': 
                    logFlag = true; 
                    logValue = optarg; 
                    break; 

            default: 
                    optErr = true; 
                    break; 

        }
    }

    cout << "flags - boxerFlag: " << boxerFlag << " logFlag: " << logFlag << endl; 

    if (boxerFlag && logFlag)
    {
        cout << "Flags are set" << endl; 
        if (logValue.empty() || boxerFile.empty())
        {
            optErr = true; 
            cout << "Option arguements are not set" << endl; 
        }
        else
        {
            ofstream flog; 
            flog.open(logValue, ios_base::app); 
            if (flog)
            {
                std::string programName = basename(argv[0]); 
                std::string msg = "The text file is: " + boxerFile + " and logfile is: " + logValue; 
                log(msg, programName, flog); 
                optErr = false;
                flog.close(); 

                    try
                    {
                        recordCount =  inputBoxers(gymBoxers, boxer, boxerFile);
                    }
                    catch (string str)
                    {
                        cout << str << " File does not exist" << endl;
                    }
                    if(recordCount)
                    {
                        cout << recordCount << " records processed" << endl; 
                        optErr=false; 

                            try
                            {
                                outputBoxers(gymBoxers, "boxers_info.txt");
                            }

                            catch (string str)
                            {
                                cout << str << " File does not exist" << endl;
                            }

                            nukeVector(gymBoxers); 
                    }

                    else 
                    {
                        optErr = true; 
                    }
                      
            }
            else
            {
                cout << "Couldn't open " << logValue << endl; 
                optErr = true; 
            }
        
        }
    }
    else 
    {
        cout << "error - Flags are not set!" << endl; 
        optErr = true; 
    }    
    
    if (optErr)
    {
        return EXIT_FAILURE; 
    }

    

    cout << "The kml file is: " << boxerFile << " and logfile is: " << logValue << endl; 
    cout << "optErr: " << optErr << endl; 


    return EXIT_SUCCESS;
    
}

int getCurrentYear()
{
	using namespace boost::gregorian; 

    date today = day_clock::local_day();  

	return today.year(); 

}

int getCurrentMonth()
{
	using namespace boost::gregorian; 

    date today = day_clock::local_day();  

	return today.month(); 
}

int inputBoxers(vector<Boxer*>& boxers, Boxer* boxer, string fileName)
{
	int recordCount = 0; 
	int age = 0; 

	bool accurateInfo = true;

	ifstream inputFile;
	inputFile.open(fileName);

	if (inputFile.fail())
	{
		throw fileName;
	}

	if (inputFile.good())
	{
		while (!inputFile.eof())
		{
			inputFile >> name >> genderInt >> birthMonth >> birthYear >> weight >> bouts;

			resizeName(name);
			
			age = calcAge(birthMonth, birthYear, currentYear, currentMonth); 

			if (!inputError(MIN_BOXER_AGE, MAX_BOXER_AGE, age, name, "Age"))
			{
				accurateInfo = false;
				cout << endl << "Cannot add " << name << ". Their age is " << age << ". Must be between " << MIN_BOXER_AGE << " and " << MAX_BOXER_AGE << endl; 
			}

			if (accurateInfo)
			{
				boxer = new Boxer(name, (Gender)genderInt, age, birthMonth, birthYear, weight, bouts);
				boxers.push_back(boxer);
				recordCount++; 

			}
		}

	}

	inputFile.close();

	return recordCount; 
}

void outputBoxers(vector<Boxer*> const& boxers, string fileName)
{
	int vecSize = boxers.size(); 
	ofstream outFile;
	outFile.open(fileName);

	if (outFile.fail())
	{
		throw fileName;
	}

	if (outFile.good())
	{

		outFile << boxerDisplay() << endl;

		for (int i = 0; i < vecSize; i++)
		{
			outFile << boxers[i]->getDescription() << endl;
		}

		tournaments(boxers, outFile); 
	}
	
	outFile.close(); 
}

void nukeVector(vector<Boxer*>& boxers)
{
	int vecSize = boxers.size();
	//cout << "VECTOR SIZE IS: " << vecSize << endl; 
	////cout << "NUKING USERS " << endl; 

	//for (int i = 0; i < vecSize; i++)
	//{
	//	//cout << boxers[i]->getDescription() << endl;
	//}


	for (int i = 0; i < vecSize; i++)
	{
	//	cout << boxers[i]->getDescription() << endl; 
		delete boxers[i]; 
		boxers[i] = nullptr; 
		//boxers.erase(boxers.begin() + i); 
	//	cout << "VECTOR SIZE IS: " << boxers.size() << endl;
	}
	//cout << "VECTOR SIZE IS: " << boxers.size() << endl;
	//cout << "CLEARING VECTOR" << endl;
	boxers.clear(); 
	//cout << "VECTOR SIZE IS: " << boxers.size() << endl;
}

bool inputError(int min, int max, int input, string name, string message)
{
	if (input < min)
	{
		cout << message << " cannot be less than " << min << endl;
		cout << name << " will need to be added manually" << endl;

		return false;
	}

	else if (input > max)
	{
		cout << message << " cannot be greater than " << max << endl;
		cout << name << " will need to be added manually" << endl;

		return false;
	}

	else
	{
		return true;
	}
}

void resizeName(string& name)
{
	int buffSize = 0;
	char space = ' ';
	int nameSize = name.size();
	if (nameSize > MAX_CHAR)
	{
		name.resize(MAX_CHAR);
	}
	else
	{
		buffSize = MAX_CHAR - nameSize;

		for (int i = 0; i < buffSize; i++)
		{
			name += space;
		}
	}
}

int calcAge(int birthMonth, int birthYear, int year, int month)
{
	int yearsOld = year - birthYear;

	if (currentMonth < birthMonth)
	{
		yearsOld -= 1;
	}

	return yearsOld;
}

string boxerDisplay()
{
	const int w = 10;
	stringstream display; 

	display << "NAME" << setw(w) << " " << "GENDER" << setw(w) << " " << "AGE" << setw(w) << " " << "WEIGHT" << setw(w) << " " << "GLOVE SIZE" << setw(w) << " "; 
	display << "BOUTS" << setw(w) << " " << "USA AGE RANGE" << setw(w) << " " << "CA AGE RANGE" << setw(w) << " " << "US ROUND TIME" << setw(w) << " " << "CA ROUND TIME"; 

	return display.str(); 
}


void tournaments(vector<Boxer*> const& boxers, ofstream& outFile)
{
	int usSilverMinAge = 10; 
	int usSilverMaxAge = 15; 
	int usSilverMonth = 5; 
	int usSilverYear = tourYear(usSilverMonth, currentMonth, currentYear); 

	int usGoldenMinAge = 17; 
	int usGoldenMaxAge = 34; 
	int usGoldenMonth = 3; 
	int usGoldenYear = tourYear(usGoldenMonth, currentMonth, currentYear);

	int caSilverMinAge = 18;
	int caSilverMaxAge = 40;
	int caSilverMonth = 10;
	int caSilverYear = tourYear(caSilverMonth, currentMonth, currentYear);
	
	int size = boxers.size(); 

	outFile << endl << "ELIGIBLE TOURNAMENTS" << endl << endl; 

	for (int i = 0; i < size; i++)
	{
		outFile << boxers[i]->getName() << endl; 
		tournamentEligible(boxers[i], usSilverYear, usSilverMonth, usSilverMinAge, usSilverMaxAge, "USA Silver Gloves", outFile); 
		tournamentEligible(boxers[i], usGoldenYear, usGoldenMonth, usGoldenMinAge, usGoldenMaxAge, "USA Golden Gloves", outFile);
		tournamentEligible(boxers[i], caSilverYear, caSilverMonth, caSilverMinAge, caSilverMaxAge, "CA Silver Gloves", outFile);
		outFile << endl; 
	}
}

void tournamentEligible(Boxer* boxer, int tourYear, int tourMonth, int minAge, int maxAge, string message, ofstream& outFile)
{
	int bMonth = boxer->getBirthMonth(); 
	int bYear = boxer->getBirthYear(); 

	int bAge = calcAge(bMonth, bYear, tourYear, tourMonth); 

	if (bAge >= minAge && bAge <= maxAge)
	{
		outFile << message << " " << tourMonth << "/" << tourYear << endl;
	}
}

int tourYear(int num1, int num2, int numYear)
{
	if (num1 < num2)
	{
		numYear += 1; 
	}

	return numYear; 
}