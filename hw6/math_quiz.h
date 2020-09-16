//Programmer: Midori Lynch             Date:10/06/19
//File: math_quiz.h                    Class: Section A
//Purpose: This file contains the  prototypes for the functions used int the
//          math quizer program

#ifndef MATH_QUIZ_H
#define MATH_QUIZ_H

using namespace std;

//Function Prototypes

//Description: The rand_num function will randomly select a value between
//  and including min_val and max_val
//Pre: None
//Post: A random number between and including min_val and max_val
//  will be returned
int rand_num (const int min_val, const int max_val);

//Description: The rand_num function will randomly select a value between
//  and including min_val and max_val
//Pre: None
//Post: A random number between and including min_val and max_val
//  will be returned
float rand_num (const float min_val, const float max_val);

//Description:
//Pre:
//Post:
bool isCorrect(const float correct_ans,const float user_ans);

//Description:
//Pre:
//Post:
bool isCorrect(const int correct_ans, const int user_ans);

//Description:
//Pre:
//Post:
void display_message(const bool correct);

//Description:
//Pre:
//Post:
void update_score(const bool correct, int & right_count, int & wrong_count);

//Description:
//Pre:
//Post:
void output_final_score(const int right_count, const int wrong_count);

//Description:
//Pre:
//Post:
template <typename U>
void output_problem(const U lhs, const U rhs, int sign)
{
  cout<<lhs<<((sign==0)?" + ":" - ")<<rhs<<" = ";
  return;
}
//Description:
//Pre:
//Post:
template <typename T>
bool the_problem(const T min_val, const T max_val)
{
  //constant variables
  const int min_sign_val=0;
  const int max_sign_val=1;
  //non-constant variables
  T answer;
  T user_ans;
  bool correct;

  //get two random vals and randomly choose between addition or subtraction
  T lhs =rand_num(min_val, max_val);
  T rhs =rand_num(min_val, max_val);
  int sign=rand_num(min_sign_val,max_sign_val);

  //output problem
  output_problem(lhs, rhs, sign);

  //compute correct answer
  answer=(sign==0)? (lhs+rhs) : (lhs-rhs);

  //get the user's answer
  cin>>user_ans;

  //check if the user's  answer is correct
  correct=isCorrect(answer,user_ans);
  display_message(correct);
  //if the user is incorrect, give them another chance.
  if(!correct)
  {
    output_problem(lhs, rhs, sign);
    cin>>user_ans;
    correct=isCorrect(answer,user_ans);
    display_message(correct);
  }

  return correct;
}

//Description:
//Pre:
//Post:
int display_menu();

//Description:
//Pre:
//Post:
void option_handler(int choice);

#endif
