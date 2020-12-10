/**
* @file utils.cpp
* @brief  Linux Final Project 
* implements functions utils.h 
* @author Luke E. Tatro 
* @Linux Final Project 
* @date 12/1/2020
*/


#include "utils.h"

using namespace std; 


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
    const int MIN_BOXER_AGE = 8;
    const int MAX_BOXER_AGE = 50;

    int currentYear = getCurrentYear(); 
    int currentMonth = getCurrentMonth(); 

    string name;
    int genderInt; 
    int birthMonth;
    int birthYear;
    int weight;
    int bouts;

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

	for (int i = vecSize - 1; i >= 0; i--)
	{
		delete boxers[i]; 
		boxers[i] = nullptr; 
		boxers.erase(boxers.begin() + i); 
	}
	boxers.clear(); 
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
    const int MAX_CHAR = 10;
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
    int currentMonth = getCurrentMonth(); 
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
    int currentYear = getCurrentYear(); 
    int currentMonth = getCurrentMonth(); 

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