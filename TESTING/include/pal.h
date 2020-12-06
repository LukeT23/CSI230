
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

enum class Gender
{
	MALE, FEMALE
};

string const GENDER_STRINGS[2]
{
	"male", "female"
};

class Boxer
{
private: 
	string name; 
	string gender; 
	int birthMonth; 
	int birthYear; 
	int age;
	int weight; 
	int bouts; 
	bool novice; 

	int gloves; 
	float roundLengthUsa; 
	float roundLengthCa; 

	int minWeight; 
	int maxWeight; 
	int minAge; 
	int maxAge; 

public:
	string getDescription(); 

	//KNOWN GETTERS AND SETTERS 
	string getName() { return name; }
	void setName(string name) { this->name = name; }

	string getGender() { return gender; }
	void setGender(Gender bGender) { this->gender = GENDER_STRINGS[(int)bGender];  }

	int getBirthMonth() { return birthMonth; }
	void setBirthMonth(int birthMonth) { this->birthMonth = birthMonth; }

	int getBirthYear() { return birthYear; }
	void setBirthYear(int birthYear) { this->birthYear = birthYear; }

	int getWeight() { return weight; }
	void setWeight(int weight) { this->weight = weight; }

	int getBouts() { return bouts;  }
	void setBouts(int bouts) { this->bouts = bouts;  }

	bool getNoive() { return novice; }
	void setNovice(int bouts); 

	//UNKOWN GETTERS AND SETTERS 
	int getAge() { return age; }
//	int setAge(int birthMonth, int birthYear); //Will take in year and month to determine age 

	int getGloves() { return gloves; }
	void setGloves(int weight, int age); 

	float getRoundLengthUsa() { return roundLengthUsa; }
	void setRoundLengthUsa(int age); 

	float getRoundLengthCa() { return roundLengthCa; }
	void setRoundLengthCa(int age, bool novice);

	int getMinWeight() { return minWeight; }
	int getMaxWeight() { return maxWeight; }
	void setWeightRange(int weight); 

	int getMinAge() { return minAge; }
	int getMaxAge() { return maxAge; }
	void setAgeRange(int age); 

	Boxer(); 
	Boxer(string name, Gender gender, int age, int birthMonth, int birthYear, int weight, int bouts);
	~Boxer(){}
};

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