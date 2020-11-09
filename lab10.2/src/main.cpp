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
#include <vector>
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>
#include "util.hpp"

using namespace std; 

int main(int argc, char* argv[])
{

    int opt{}; 
    bool kmlFlag{false}; 
    bool logFlag{false}; 
    string logValue; 
    string kmlValue; 
    bool optErr = true; 


    while((opt = getopt(argc, argv, "k:l:")) != EOF)
    {
        switch(opt)
        {
            case 'k': 
                    kmlFlag = true; 
                    kmlValue = optarg; 
                    break; 

            case 'l': 
                    logFlag = true; 
                    logValue = optarg; 
                    break; 

            default: 
                    optErr = true; 
                    break; 

        }
    }

    cout << "flags - kmlFlag: " << kmlFlag << " logFlag: " << logFlag << endl; 

    if (kmlFlag && logFlag)
    {
        cout << "Flags are set" << endl; 
        if (logValue.empty() || kmlValue.empty())
        {
            optErr = true; 
            cout << "Option arguements are not set" << endl; 
        }
        else
        {
            ofstream flog; 
            flog.open(logValue, ios_base::app); 
            if (flog)
            {
                std::string programName = basename(argv[0]); 
                std::string msg = "The kmlfile is: " + kmlValue + " and logfile is: " + logValue; 
                log(msg, programName, flog); 
                optErr = false;
                flog.close(); 
            }
            else
            {
                cout << "Couldn't open " << logValue << endl; 
                optErr = true; 
            }
        
        }
    }
    else 
    {
        cout << "error - Flags are not set!" << endl; 
        optErr = true; 
    }    
    
    if (optErr)
    {
        return EXIT_FAILURE; 
    }



    cout << "The kml file is: " << kmlValue << " and logfile is: " << logValue << endl; 
    cout << "optErr: " << optErr << endl; 


    return EXIT_SUCCESS;
    
}