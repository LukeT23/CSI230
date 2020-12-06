/**
* @file boxers.h
* @brief  Linux Final Project 
* creates a boxer class and handles the creation of objects 
* @author Luke E. Tatro 
* @Linux Final Project 
* @date 12/1/2020
* 
*/

#ifndef BOXERS_H
#define BOXERS_H 

#include <string> 
#include <fstream> 
#include <vector> 

using namespace std; 

/**
* @brief process a country csv file 
* @date 11/8/2020
* @return returns the number of records processed  
* @param infFile ifstream to an opened and valibated csv file 
* @param kmlFileName std:string containing hte name of hte kml file you wish to produce 
* @param logFile ofstream reference, validation of this file is epxected
*/


#include <string>

using namespace std; 

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


#endif 
