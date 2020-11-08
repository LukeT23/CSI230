#ifndef UTIL_HPP
#define UTIL_HPP
#include <string>
#include <vector>

using namespace std; 

const int NAME_ARRAY_SIZE = 6; 

string randomElement(vector<string>); 
double sum(vector<double>);
double avg(vector<double>);
double lowest(vector<double>); 

string camelCase(string &); 

#endif 