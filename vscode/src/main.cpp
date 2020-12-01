/**
* @file week10.cpp
* @brief  Week 10, C++ Review and Warmup from CSI230 
* @author Luke E. Tatro
* @assignment Lecture 10.1
* @date 10/26/2020
* @credits
* 
*/

#include <iostream>
#include <vector>
#include <unistd.h> 
#include <ctime>
#include "util.hpp"

using namespace std; 

int main()
{
    srand((int)time(NULL));

    vector<string> names = {"Luke", "Todd", "Mark", "Bill", "Kyle" }; 
    vector<double> myDoubles = { 15.4, 12.3, 5.7, 9.2, 8.5 };

    string birdie = "A little bird with a yellow bill"; 

    cout << "Here are the elemnts in the vector of strings: " << endl; 
    for (string c : names)
    {
        cout << c << " "; 
    }

    cout << endl << endl; 

    cout << "Here is a random element: " << randomElement(names) << endl; 
    
    cout << "Here are the elemnts in the vector of doubles: " << endl;
    for (double i : myDoubles)
    {
        cout << i << " ";
    }

    cout << endl << endl;
    
    cout << "Sum of the doubles: " << sum(myDoubles) << endl; 
    cout << "Average of the doubles: " << avg(myDoubles) << endl; 
    cout << "Lowest of the doubles: " << lowest(myDoubles) << endl << endl;  
    cout << "Here are the words: " << birdie << endl; 
    cout << "Words written by a Marine with a crayon: " << camelCase(birdie) << endl; 

    cout << endl; 

    char name[256]; 
    // << a character array to a 
    gethostname(name, 10); 

    cout << endl << name << endl; 

    return EXIT_SUCCESS; 
    
}