//Programmer: Midori Lynch             Date:10/06/19
//File: math_quiz.cpp                  Class: Section A
//Purpose: This file contains the main function for the math quizer
//         for entertainment on Dr. Nick's vacation

#include <iostream>
#include <cstdlib>
#include "math_quiz.h"

using namespace std;

int main()
{
  //Seeds random number generator
  srand(time(NULL));
  //constant variables
  const int NUM_OF_PROBS=3;
  const int QUIT_VALUE=4;
  //non-constant variables
  int choice;

  do
  {
    choice=display_menu();
    //to reading a string

    //only output a set of problems if the user doesn't want to quit
    if (choice==QUIT_VALUE)
    {
      option_handler(choice);
    }
    else
    {
      //Output num_of_probs math problems
      for (int i=1;i<=NUM_OF_PROBS;i++)
      {
        option_handler(choice);
      }
    }
  } while (choice!=QUIT_VALUE);//keep displaying the menu after the user's
  //set of problems is done until they quit

  return 0;
}
