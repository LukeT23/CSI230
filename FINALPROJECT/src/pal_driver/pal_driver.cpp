/**
* @file week10.cpp
* @brief  Week 10, C++ Review and Warmup from CSI140
* @author Luke E. Tatro 
* @credit Bilbo Baggins
* @assignment Lecture 10.1
* @date 10/26/2020
* @credits
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

int getCurrentYear(); 

int getCurrentMonth(); 

int inputBoxers(vector<Boxer*>& boxers, Boxer* boxer, string fileName);

void outputBoxers(vector<Boxer*> const& boxers, string fileName); 

void nukeVector(vector<Boxer*>& boxers); 

bool inputError(int min, int max, int input, string name, string message); 

void resizeName(string& name);

int calcAge(int birthMonth, int birthYear, int year, int month);

string boxerDisplay(); 

void tournaments(vector<Boxer*> const& boxers, ofstream& outFile);

void  tournamentEligible(Boxer* boxer, int tourYear, int tourMonth, int minAge, int maxAge, string message, ofstream& outFile);

int tourYear(int num1, int num2, int numYear); 

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

	std::cout << std::endl << today.year() << std::endl; 

	return today.year(); 

}

int getCurrentMonth()
{
	using namespace boost::gregorian; 

    date today = day_clock::local_day(); 

	std::cout << std::endl << today.month() << std::endl; 

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
	//int monthsDifference;
	//int monthsOld = 0;

	if (currentMonth < birthMonth)
	{
		//monthsDifference = birthMonth - month;
		//monthsOld = 12 - monthsDifference;
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