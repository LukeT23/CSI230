#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "util.hpp"

using namespace std; 

string randomElement(vector<string> names) 
{
	int random = -1; 
	

	while (random == -1 || random > 4)
	{ 
		random = rand() % names.size() + 1; 
	}

	return names[random]; 
}


double sum(vector<double> nums)
{
	double total = 0; 

	for (double i : nums)
	{
		total += i; 
	}

	return total; 
}

double avg(vector<double> nums)
{
	return sum(nums)/(nums.size()); 
}

double lowest(vector<double> nums)
{
	double low = nums[0]; 

	for (double current : nums)
	{
		if (current < low)
		{
			low = current; 
		}
	}

	return low; 

}


string camelCase(string &words)
{
	char blank = ' '; 
	int index = 0; 
	int size = words.size(); 

	words[0] = tolower(words[0]); 

	for (int i = 0; i < words.size(); i++)
	{
		if (words[i] == blank)
		{
			words[i + 1] = toupper(words[i +1]); 
			words.erase(i, 1); 
		}
	}

	return words; 
}