//File: math_quiz_fncts.cpp            Class: Section A
//Purpose: This file contains the function definitions for the functions
//         used in the math quizer program.

#include <iostream>
#include <cstdlib>
#include "math_quiz.h"
using namespace std;

//Description: The rand_num function will randomly select a value between
//  and including min_val and max_val
//Pre: None
//Post: A random number between and including min_val and max_val
//  will be returned
int rand_num(const int min_val, const int max_val)
{
  return rand() % (max_val-min_val+1) + min_val;
}

//Description: The rand_num function will randomly select a value between
//  and including min_val and max_val
//Pre: None
//Post: A random number between and including min_val and max_val
//  will be returned
float rand_num (const float min_val, const float max_val)
{
  //makes the decimal an integer so it can be used to find a random number
  int min_val_int=static_cast<int>(min_val*100);
  int max_val_int=static_cast<int>(max_val*100);

  //If a float w/ more than two decimal places is passed to the function
  //this will truncate the decimal until it only has two decimal places
  while (min_val_int>=10000)
  {
    min_val_int/=10;
  }
  while (max_val_int>=10000)
  {
    max_val_int/=10;
  }
  //finds a random int between min_val_int and max_val_int
  int rand_val=rand() % (max_val_int-min_val_int+1) + min_val_int;

  //makes the random int have two decimal places, therefore making it
  //within the inputted range
  return static_cast<float>(rand_val)/100;
}

int display_menu()
{
  int choice;

  cout<<"Difficulty level"<<endl;
  cout<<"1. Easy"<<endl;
  cout<<"2. Moderate"<<endl;
  cout<<"3. Advanced"<<endl;
  cout<<"4. Quit"<<endl<<endl;
  cout<<"Enter your choice: ";

  cin>>choice;

  return choice;
}

void option_handler(int choice)
{
  //variables
  int min_int=0;
  int max_one_int=9;
  int max_two_ints=99;
  float min_float=0.00;
  float max_float=99.99;
  //non constant vars
  static int num_correct=0;
  static int num_incorrect=0;
  bool correct=false;

  //action based on choice
  switch (choice)
  {
    case 1:
      correct=the_problem(min_int,max_one_int);
      update_score(correct,num_correct,num_incorrect);
      break;
    case 2:
      correct=the_problem(min_int,max_two_ints);
      update_score(correct,num_correct,num_incorrect);
      break;
    case 3:
      correct=the_problem(min_float,max_float);
      update_score(correct,num_correct,num_incorrect);
      break;
    case 4:
      cout.setf(ios::fixed);
      cout.setf(ios::showpoint);
      cout.precision(2);
      output_final_score(num_correct,num_incorrect);
      cout<<"Thank you for using the math quizer program."<<endl;
      break;
    default:
      cout<<"An error has occured"<<endl;
      break;
  }
  return;
}

bool isCorrect(const float correct_ans, const float user_ans)
{
  //constant in order to get the right correctness val when comparing floats
  const float ANS_PRECIS=0.005;
  //variable to be returned
  bool correct=false;

  if (correct_ans<(user_ans+ANS_PRECIS) && correct_ans>(user_ans-ANS_PRECIS))
  {
    correct=true;
  }
  return correct;
}

bool isCorrect(const int correct_ans, const int user_ans)
{
  return ((correct_ans==user_ans) ? true : false);
}

void display_message(const bool correct)
{
  cout<<(correct? "Correct." : "Incorrect.")<<endl;
}

void update_score(const bool correct, int & right_count, int & wrong_count)
{
  correct? (right_count++) : (wrong_count++);
}

void output_final_score(const int right_count, const int wrong_count)
{
  float percentage;
  int total=right_count+wrong_count;

  percentage=((static_cast<float>(right_count))/total)*100;

  cout<<"Total correct: "<<right_count<<endl;
  cout<<"Total incorrect: "<<wrong_count<<endl;

  cout<<"Percentage correct: "<<percentage<<"%"<<endl;
}
