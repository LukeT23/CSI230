/**
* @file boxers.cpp
* @brief  Linux Final Project 
* implements functions and constructors from boxer.h 
* @author Luke E. Tatro 
* @Linux Final Project 
* @date 12/1/2020
* 
*/

#include "boxers.h"


using namespace std; 

string Boxer::getDescription()
{
	int const WIDTH = 10; 

	stringstream strStream;

	string gSize = getGender(); 
	int genderBuffer = WIDTH - gSize.size();

	int ageBuffer = this->setBuffer(getAge(), 2); 
	int boutBuffer = this->setBuffer(getBouts(), 2); 
	int weightBuffer = this->setBuffer(getWeight(), 3); 

	int usAgeBuffer = this->rangeBuffer(getMinAge(), getMaxAge(), 4);
	int caAgeSize1 = this->rangeBuffer(getMinAge(), getBirthMonth(), 4);
	int caAgeSize2 = this->rangeBuffer(getMaxAge(), getBirthMonth(), 4);
	int caAgeBuffer = caAgeSize1 + caAgeSize2; 

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

int Boxer::rangeBuffer(int num1, int num2, int size)
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

int Boxer::setBuffer(int num, int size)
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
