/**
* @file main.cpp
* @brief  Week 11 Boost Library Lab
* @author Luke E. Tatro
* @assignment Lecture 11.2
* @date 11/13/2020
* @credit Devin Paden 
* 
*/

#include <boost/program_options.hpp>
#include <boost/foreach.hpp> 
#include <string> 
#include <iostream>

using namespace boost::program_options;

/**
 * @brief creates an array and prints out elements in order and reverse
 * @date 11/15/2020
 * @param int takes an int param for size of array and as a multiplier  
 * 
 */

void array_op(int num)
{
  std::cout << "Entering the array_op function" << std::endl; 
  std::cout << "Multiplier is: " << num << '\n';

  int strArray[num];  
  std::string numbers; 
  for (int i = 0; i < num; i++)
  {
    strArray[i] = (i + 1) * num;
    std::string strNum = std::to_string(strArray[i]) + " ";  
    numbers = numbers + strNum; 
  } 

  std::cout << "Entering the BOST_FOREACH loops" << std::endl; 
  std::cout << "The multiples of " << num << " from 1 to " << num << " are: "; 

    BOOST_FOREACH( char c, numbers )
    {
        std::cout << c;
    }

    std::cout << std::endl; 

  std::cout << "These numbers reversed are:"; 

    BOOST_REVERSE_FOREACH(char c, numbers)
    {
        std::cout << c; 
    }

    std::cout << std::endl; 
}

int main(int argc, const char *argv[])
{
  try
  {
    options_description desc{"Options"};
    desc.add_options()
      ("help,h", "Help screen")
      ("multiplier", value<int>()->notifier(array_op), "multiplier");

    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);

    if (vm.count("help"))
      std::cout << desc << '\n';
    else if (vm.count("multiplier"))
      std::cout << "Your multiplier was: " << vm["multiplier"].as<int>() << '\n';
  }
  catch (const error &ex)
  {
    std::cerr << ex.what() << '\n';
  }
}

