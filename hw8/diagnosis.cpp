/Programmer: Midori Lynch             Date: 10/21/19
//File: diagnosis_fncts.cpp            Class: CS1570 Section A
//Purpose: This file contains the main function for Dr. Nick's automated
//         doctor program.

#include <iostream>

#include "DIAGNOSIS.H"

using namespace std;

int main()
{
  /*----------------------SEEDING RANDOM NUMBER---------------------------*/
  srand(time(NULL));

  /*---------------------------DECLARATIOS-------------------------------*/
  //constant vars
  const short COMPLAINT_SIZE=2100;
  //Max of 100 words * max size of word 20 = 2000
  // then you will have a max of 99 spaces + NULL char 2000+99+1=2100
  const short MAX_RAND_WORDS=5;
  const short LONGEST_FILE_NAME=5;
  const short MAX_WORD_SIZE=20;

  //nonconstant vars
  char complaint[COMPLAINT_SIZE];
  short wordsInComp;
  short numRandCompWords;
  char fileName[LONGEST_FILE_NAME];

  /*----------------------------INPUT-----------------------------------*/
  cout<<"-------------- Dr. Nick's Health-o-Mattock ---------------"<<endl;
  cout<<"What is your issue: ";
  get_complaint(complaint, COMPLAINT_SIZE);

  /*-----------------------COMPUTATIONS AND OUTPUT----------------------*/
  wordsInComp=get_num_words(complaint, COMPLAINT_SIZE);

  numRandCompWords=((wordsInComp/2)>MAX_RAND_WORDS)? MAX_RAND_WORDS:
    ((wordsInComp)/2);

  cout<<"So, ";
  output_n_rand_words(complaint, wordsInComp, numRandCompWords);
  cout<<"?";

  find_file_name(complaint, fileName);

  return 0;
}
