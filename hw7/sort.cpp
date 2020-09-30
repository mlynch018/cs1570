//Programmer: Midori Lynch             Date: 10/12/19
//File: sort.cpp                       Class: Section A
//Purpose: This file contains the function defintions for the functions
//  used in Dr. Nick's sorting algorithm evaluator program.

#include <iostream>
#include <ctime>

#include "sort.h"

using namespace std;

void populate_int_arr(int arr[],const short size,const int min,const int max)
{
  for (short i=0; i<size; i++)
  {
    arr[i]=rand() % (max-min+1) + min;
  }

  return;
}

