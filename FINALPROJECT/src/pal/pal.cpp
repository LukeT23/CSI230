/**
* @file pal.cpp
* @brief  Linux Final Project 
* implements functions pal.h 
* @author Luke E. Tatro 
* @Linux Final Project 
* @date 12/1/2020
* @credit Devin Paden 
*/

#include "boxers.h"
#include "pal.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <ctime> 
#include <unistd.h>

using  namespace std; 

bool log(std::string msg, std::string programName, std::ofstream& logFile)
{
	bool retVal = false; 
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

	// get the pid take the info and headers from main and put them here
	pid_t pid = getpid(); 
	//get the hostname (I haven't shown you this) used a function called gethostname 
	//get host name takes a char pointer and a length of bits. 
	std::string strHostName; 
	char hName[256];
	gethostname(hName, 10); 

	strHostName = hName; 
	
	if (logFile)
	{
		
		//write the log
		// add pid after the program name so that it looks like:    program[pid]
		logFile << strTime << strHostName << " " << programName << "[" << pid << "]: " << msg << std::endl; 

		retVal = true; 
	}

	return retVal; 
}

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

int currentYear = 2020;
int currentMonth = 12;
int const MONTHS_IN_YEAR = 12;



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

int rangeBuffer(int num1, int num2, int size)
{
	int retVal = 0; 
	
	string numWords = (to_string(num1) + to_string(num2));

	int valueSize = (numWords.size());

	if (valueSize < size)
	{
		retVal = size - valueSize;
	}

	return retVal;
}

int setBuffer(int num, int size)
{ 
	string makeString = to_string(num); 
	int valueSize = makeString.size(); 

	int retVal = 0; 
	
		if (valueSize < size)
		{
			retVal = size - valueSize; 
		}
	
	return retVal; 
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