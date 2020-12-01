/*
* @file PAL.CPP
* @brief  Vowel/Consonant Declarations 
* @author Luke E. Tatro 
* @credit written by: https://www.fayewilliams.com/2015/07/07/creating-a-shared-library/
* @assignment Lecture 12.1
* @date 11/30/2020
* 
*/


#include "pal.h"
#include <string.h>
#include <iostream>

using namespace std; 


bool isVowel(char ch)
{
    bool retVal = false; 
    if (ch == 'a'){retVal = true;}
    if (ch == 'e'){retVal = true;}
    if (ch == 'i'){retVal = true;}
    if (ch == 'o'){retVal = true;}
    if (ch == 'u'){retVal = true;}

    return retVal; 
}

void letters (char* word)
{
    int vowels = 0; 
    int consonants = 0; 
    int len = strlen(word);

    
    for (int i = 0; i < len; i++) 
    {
        if(isVowel(word[i]))
        {
            vowels++; 
        }
        if(!isVowel(word[i]))
        {
            consonants++; 
        }
        
    }
    
    cout << endl << "Your word contains " << endl; 
    cout << vowels << " vowels" << endl; 
    cout << consonants << " consonants" << endl; 
}