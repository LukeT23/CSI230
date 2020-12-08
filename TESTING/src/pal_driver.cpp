/**
* @file week10.cpp
* @brief  Week 10, C++ Review and Warmup from CSI140
* @author Luke E. Tatro 
* @credit Bilbo Baggins
* @assignment Lecture 10.1
* @date 10/26/2020
* @credits
* 
*/


#include <iostream>

#include <string>
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>
#include "boost/date_time/gregorian/gregorian.hpp"


using namespace std; 

int main()
{

    using namespace boost::gregorian; 

    date today = day_clock::local_day(); 

    std::cout << today << std::endl; 
    std::cout << today.month() << std::endl; 
    std::cout << today.year() << std::endl; 

    int year = today.year(); 
    int month = today.month(); 
    std::cout << year << "/" << month << std::endl; 


    return EXIT_SUCCESS;
    
}