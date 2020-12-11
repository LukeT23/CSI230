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

	/**
	* @brief Puts all boxer's info in readable format  
	* @date 12/10/2020
	* @return returns a string of the boxer's info 
	*/

	string getDescription(); 

	/**
	* @brief Used to set and get the number of bouts(fights) a boxer has had 
	* @date 12/10/2020
	* @return returns the number of bouts 
	* @param int bouts used to set the number of fights a boxer has had 
	*/

	int getBouts() { return bouts;  }
	void setBouts(int bouts) { this->bouts = bouts;  }

	/**
	* @brief Used to set and get if a boxer is Novice (less than 10 fights) 
	* @date 12/10/2020
	* @return returns a bool as true if boxer's fights are less than 10 
	* @param int bouts to enter the number of fights a boxer has had 
	*/

	bool getNovice() { return novice; }
	void setNovice(int bouts); 

	/**
	* @brief Used to set and get the size of gloves a boxer needs  
	* @date 12/10/2020
	* @return returns an int as the weight of the boxer's gloves 
	* @param int weight to take in the boxer's weight 
	* @param int age to take in the boxer's age 
	*/

	int getGloves() { return gloves; }
	void setGloves(int weight, int age); 

	/**
	* @brief Used to set a space buffer between a range of integer values in getDescription 
	* @date 12/10/2020
	* @return returns an int that will be used as a space buffer 
	* @param int num1 and num2 are converted into strings and combined to determine the total
	*			 character length of the numbers 
	* @param int size is used to compare the total character length of numbers to determine how 
	*			 large the buffer must be 
	*/

	int rangeBuffer(int num1, int num2, int size); 

	/**
	* @brief Used to set a space buffer between single integer values in getDescription 
	* @date 12/10/2020
	* @return returns an int that will be used as a space buffer 
	* @param int num1 is converted into a string determine the character length of the number 
	* @param int size is used to compare the character length of number to determine how 
	*			 large the buffer must be 
	*/

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
