/**
 * @file pal_driver.cpp
 * @brief Vowel/Consonant Library Driver
 * @author Luke E. Tatro 
 * @credit written by: https://www.fayewilliams.com/2015/07/07/creating-a-shared-library/
 * @assignment 12.1 
 * @date 11/30/2020
 * 
 */


#include "pal.h"
#include <iostream> 

using namespace std;

int main()
{
    while (1)
    {
        char buffer[64] = {0};
        cin >> buffer;

        letters(buffer); 
    }

    return 0;
} 