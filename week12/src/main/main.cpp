/**
 * @file main.cpp
 * @brief Palinrome Library Driver
 * 
 * @author Luke E. Tatro 
 * credit written by: 
 * @assignment 12.1 
 * @date 11/17/2020
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

        if (isPalindrome(buffer))
        {
            cout << "Word is a palindrome" << endl;
        }
        else
        {
            cout << "Word is not a palindrome" << endl;
        }
    }

    return 0;
} 