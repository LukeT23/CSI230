/**
* @file pal_driver.cpp
* @brief  Linux Final Project 
* Runs the program taking in a file name and outputting it into a new file 
* @author Luke E. Tatro
* @credit Devin Paden  
* @Linux Final Project 
* @date 12/1/2020
* 
*/

#include "pal.h"
#include "boxers.h"
#include "utils.h"
#include "boost/date_time/gregorian/gregorian.hpp" //EXTERNAL LIBRARY 

using namespace std; 


int main(int argc, char* argv[])
{

    int opt{}; 
    int recordCount = 0; 
    bool boxerFlag{false}; 
    bool logFlag{false}; 
    string logValue; 
    string boxerFile; 
    bool optErr = true; 

    string coraName = "Cora"; 
    resizeName(coraName); 
    vector<Boxer*> gymBoxers;
    Boxer* boxer = new Boxer(coraName, Gender::FEMALE, 13, 4, 2007, 115, 8); 
    gymBoxers.push_back(boxer);


    while((opt = getopt(argc, argv, "k:l:")) != EOF)
    {
        switch(opt)
        {
            case 'k': 
                    boxerFlag = true; 
                    boxerFile = optarg; 
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

    cout << "flags - boxerFlag: " << boxerFlag << " logFlag: " << logFlag << endl; 

    if (boxerFlag && logFlag)
    {
        cout << "Flags are set" << endl; 
        if (logValue.empty() || boxerFile.empty())
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
                std::string msg = "The text file is: " + boxerFile; 
                log(msg, programName, flog); 
                optErr = false;
                flog.close(); 

                    try
                    {
                        recordCount =  inputBoxers(gymBoxers, boxer, boxerFile);
                    }
                    catch (string str)
                    {
                        cout << str << " File does not exist" << endl;
                    }
                    if(recordCount)
                    {
                        cout << recordCount << " records processed" << endl; 
                        optErr=false; 

                            try
                            {
                                outputBoxers(gymBoxers, "boxers_info.txt");
                            }

                            catch (string str)
                            {
                                cout << str << " File does not exist" << endl;
                            }

                            nukeVector(gymBoxers); 
                    }

                    else 
                    {
                        optErr = true; 
                    }
                      
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

    

    cout << "The boxer file is: " << boxerFile << endl; 
    cout << "optErr: " << optErr << endl; 


    return EXIT_SUCCESS;
    
}

