/**
* @file util.hpp
* @brief  C++ warm up 
* handles the delcaration of all logging functionality 
* @author Luke E. Tatro 
* @assignment Lecture 10.1
* @date 11/5/2020
* @credits
* 
*/


#ifndef UTIL_HPP
#define UTIL_HPP
#include <string>
#include <vector>

using namespace std; 

/**
 * @brief pulls a random element from a vector
 * @date 11/5/2020
 * @return returns a string from the vector 
 * @param vector containing strings 
 * 
 */

string randomElement(vector<string>); 

/**
 * @brief creates a sum of elements in a vector
 * @date 11/5/2020
 * @return returns a double 
 * @param vector containing doubles  
 * 
 */
double sum(vector<double>);

/**
 * @brief creates an average of the elements in a vector
 * @date 11/5/2020
 * @return returns a double 
 * @param vector containing doubles  
 * 
 */

double avg(vector<double>);

/**
 * @brief finds the lowest of the elements in a vector
 * @date 11/5/2020
 * @return returns a double 
 * @param vector containing doubles  
 * 
 */

double lowest(vector<double>); 

/**
 * @brief changes a string into camel case text 
 * @date 11/5/2020
 * @return returns a string 
 * @param a string variable by reference   
 * 
 */

string camelCase(string &); 

#endif 