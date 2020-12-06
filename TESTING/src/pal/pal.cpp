/**
* @file helpers.cpp
* @brief  Linux Final Project 
* implements functions helpers.h 
* @author Luke E. Tatro 
* @Linux Final Project 
* @date 12/1/2020
* 
*/

#include "pal.h"
#include <iostream>
#include <vector>
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

string Boxer::getDescription()
{
	int const WIDTH = 10; 
	//int gWidth = 0; 
	stringstream strStream;

	string gSize = getGender(); 
	int genderBuffer = WIDTH - gSize.size();

	int ageBuffer = setBuffer(getAge(), 2); 
	int boutBuffer = setBuffer(getBouts(), 2); 
	int weightBuffer = setBuffer(getWeight(), 3); 

	int usAgeBuffer = rangeBuffer(getMinAge(), getMaxAge(), 4);
	int caAgeSize1 = rangeBuffer(getMinAge(), getBirthMonth(), 4);
	int caAgeSize2 = rangeBuffer(getMaxAge(), getBirthMonth(), 4);
	int caAgeBuffer = caAgeSize1 + caAgeSize2; 



	//int width = 0;

	strStream << getName() << setw(4) << " " << getGender() << setw(genderBuffer+6) << " " << getAge() << setw(ageBuffer + 11) << " " << getWeight() << setw(weightBuffer + 13) << " " << getGloves() << setw(18) << " " << getBouts();
	strStream << setw(boutBuffer + 13) << " " << getMinAge() << " - " << getMaxAge() << setw(usAgeBuffer + 16) << " " << getMinAge() << "." << getBirthMonth() << " - " << getMaxAge() << "." << getBirthMonth();
	strStream << setw(caAgeBuffer + 9) << " " << setiosflags(ios::fixed) << setprecision(1) << getRoundLengthUsa() << " minutes" << setw(12) << " " << setprecision(1) << getRoundLengthCa() << " minutes";

	return strStream.str();
}

void Boxer::setNovice(int bouts)
{
	
	if (bouts >= 10)
	{
		this->novice = false; 
	}

	if (bouts < 10)
	{
		this->novice = true;
	}
	
}

void Boxer::setGloves(int weight, int age)
{
	if (age >= 35)
	{
		this-> gloves = 16; 
	}

	else
	{
		if (weight <= 141)
		{
			this->gloves = 10;
		}

		if (weight > 141)
		{
			this->gloves = 12;
		}
	}
}

void Boxer::setRoundLengthUsa(int age)
{
	if (age >= 8 && age <= 12)
	{
		this->roundLengthUsa = 1; 
	}

	if(age == 13 || age == 14)
	{
		this->roundLengthUsa = 1.5;
	}

	if (age == 15 || age == 16)
	{
		this->roundLengthUsa = 2;
	}

	if (age >= 17 && age <= 35)
	{
		this->roundLengthUsa = 3;
	}

	if (age > 35)
	{
		this->roundLengthUsa = 2;
	}
}

void Boxer::setRoundLengthCa(int age, bool novice)
{
	if (novice)
	{
		if (age >= 15)
		{
			this->roundLengthCa = 2; 
		}

		if (age == 13 || age == 14)
		{
			this->roundLengthCa = 1.5;
		}

		if (age < 13)
		{
			this->roundLengthCa = 1;
		}
	}

	if (!novice)
	{
		if (age >= 17)
		{
			this->roundLengthCa = 3;
		}

		if (age == 15 || age == 16)
		{
			this->roundLengthUsa = 2;
		}

		if (age == 13 || age == 14)
		{
			this->roundLengthUsa = 1.5;
		}

		if (age < 13)
		{
			this->roundLengthCa = 1;
		}
	}
}

void Boxer::setWeightRange(int weight)
{
	if (age < 17)
	{
		if (weight <= 105)
		{
			this->minWeight = weight - 5; 
			this->maxWeight = weight + 5; 
		}

		if (weight == 106 || weight == 107)
		{
			this->minWeight = 101; 
			this->maxWeight = weight + 7; 
		}

		if (weight >= 108)
		{
			this->minWeight = weight - 7;
			this->maxWeight = weight + 7;
		}

		if (weight >= 125)
		{
			this->minWeight = weight - 9;
			this->maxWeight = weight + 9;
		}

		if (age == 11 || age == 12)
		{
			if (weight >= 145)
			{
				this->minWeight = weight - 12;
				this->maxWeight = weight + 12;
			}
		}

		if (age == 13 || age == 14)
		{
			if (weight > 154)
			{
				this->minWeight = weight - 12;
				this->maxWeight = weight + 12;
			}
		}

		if (age == 15 || age == 17)
		{
			if (weight >= 165)
			{
				this->minWeight = weight - 12;
				this->maxWeight = weight + 12;
			}
			if (weight > 176)
			{
				this->minWeight = weight - 12;
				this->maxWeight = 300;
			}
		}
	}
	if (age >= 17)
	{
		string boxerGender = this->gender;

			if (boxerGender == "female")
			{
				if (weight >= 106)
				{
					this->minWeight = weight - 8;
					this->maxWeight = 8;
				}
				if (weight >= 132)
				{
					this->minWeight = weight - 10;
					this->maxWeight = 10;
				}
				if (weight >= 165)
				{
					this->minWeight = weight - 12;
					this->maxWeight = 12;
				}
				if (weight > 176)
				{
					this->minWeight = weight - 12;
					this->maxWeight = 300;
				}
			}

			else
			{
				if (weight >= 108)
				{
					this->minWeight = weight - 6;
					this->maxWeight = 6;
				}
				if (weight >= 123)
				{
					this->minWeight = weight - 8;
					this->maxWeight = 8;
				}
				if (weight >= 141)
				{
					this->minWeight = weight - 10;
					this->maxWeight = 10;
				}
				if (weight >= 178)
				{
					this->minWeight = weight - 15;
					this->maxWeight = 15;
				}
				if (weight > 201)
				{
					this->minWeight = weight - 15;
					this->maxWeight = 300;
				}
			}	
	}
}

void Boxer::setAgeRange(int age)
{
	if (age == 8)
	{
		this->minAge = 8; 
		this->maxAge = 9; 
	}
	if (age == 9)
	{
		this->minAge = 8;
		this->maxAge = 11;
	}
	if (age == 10)
	{
		this->minAge = 9;
		this->maxAge = 12;
	}
	if (age == 11)
	{
		this->minAge = 9;
		this->maxAge = 13;
	}
	if (age == 12)
	{
		this->minAge = 10;
		this->maxAge = 14;
	}
	if (age == 13)
	{
		this->minAge = 11;
		this->maxAge = 15;
	}
	if (age == 14)
	{
		this->minAge = 12;
		this->maxAge = 16;
	}
	if (age == 15)
	{
		this->minAge = 13;
		this->maxAge = 17;
	}
	if (age == 16)
	{
		this->minAge = 14;
		this->maxAge = 17;
	}
	if (age == 17)
	{
		this->minAge = 15;
		this->maxAge = 18;
	}
	if (age == 18)
	{
		this->minAge = 17;
		this->maxAge = 35;
	}
	if (age > 18)
	{
		this->minAge = 18;
		this->maxAge = 35;
	}
	if (age > 35)
	{
		this->minAge = age - 10;
		this->maxAge = age + 10;
	}
}

Boxer::Boxer()
{
	this->name = "Bob"; 
	this->gender = "Male"; 
	this->age = 0;
	this->birthMonth = 0;
	this->birthYear = 0; 
	this->weight = 0; 
	this->bouts = 0; 
	this->novice = false; 
	this->gloves = 0; 
	this->roundLengthCa = 0; 
	this->roundLengthUsa = 0; 
	this->minAge = 0; 
	this->maxAge = 0; 
	this->minWeight = 0;
	this->maxWeight = 0; 
}
Boxer::Boxer(string name, Gender genderInt, int age, int birthMonth, int birthYear, int weight, int bouts)
{
	this->name = name;
	this->gender = GENDER_STRINGS[(int)genderInt];
	this->age = age;
	this->birthMonth = birthMonth;
	this->birthYear = birthYear; 
	this->weight = weight;
	this->bouts = bouts;
	
	setNovice(bouts); 
	setGloves(weight, age);
	setRoundLengthUsa(age);
	setRoundLengthCa(age, novice);
	setWeightRange(weight);
	setAgeRange(age);
}
 
 

