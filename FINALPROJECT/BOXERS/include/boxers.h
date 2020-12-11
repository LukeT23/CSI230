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
#include <sstream> 
#include <iostream> 
#include <iomanip>

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

	//SETTERS AND GETTERS 

	string getDescription(); 

	//Retrieve the number of fights a boxer has had 
	int getBouts() { return bouts;  }
	void setBouts(int bouts) { this->bouts = bouts;  }

	//Determine if a boxer is Novice (Less than 10 fights)
	bool getNovice() { return novice; }
	void setNovice(int bouts); 

	//Determine boxer's glove weight in ounces
	int getGloves() { return gloves; }
	void setGloves(int weight, int age); 

	//Set a space buffer for values in getDescription that are ranges such as age bracket and weight division 
	int rangeBuffer(int num1, int num2, int size); 

	//Sets a space buffer so single integer values such as weight and glove size
	int setBuffer(int num, int size); 


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

	int getAge() { return age; }

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
