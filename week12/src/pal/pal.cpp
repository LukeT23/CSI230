
/*
* @file PAL.CPP
* @brief  Palindrome Declarations 
* @author Luke E. Tatro 
* @credit written by: https://www.fayewilliams.com/2015/07/07/creating-a-shared-library/
* @assignment Lecture 12.1
* @date 11/17/2020
* 
*/


#include "pal.h"
#include <string.h>

using namespace std; 

bool isPalindrome(char* word)
{
    bool ret = true;

    char *p = word;
    int len = strlen(word);
    char *q = &word[len-1];

    for (int i = 0 ; i < len; ++i, ++p, --q)
    {
        if (*p != *q)
        {
            ret = false;
        }
    }
    return ret;
} 