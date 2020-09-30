//Programmer: Midori Lynch             Date: 10/12/19
//File: sort.h                         Class: Section A
//Purpose: This file contains the template functions and prototypes
//  for the functions in Dr. Nick's sorting algorithm evaluator program.


#ifndef SORT_H
#define SORT_H

#include <iostream>
using namespace std;

//Description: This function populates arr[] with random values between
//  and including min and max.
//Pre: Max must be greater than min. Size must be greater than or equal to
//  zero.
//Post: arr[] will be populated with random values between and including
//  min and max.
void populate_int_arr(int arr[],const short size,const int min,const int max);

//Description: This function puts all of the values contained in original[]
//  into the corresponding positions of duplicate[]
//Pre: The size of duplicate[] must be greater than or equal to the size of
//  original[]. size must be greater than or equal to zero.
//Post: Duplicate[] will contain the same data as original[] up to size
//  number of elements.
template <typename T>
void copy_arr_data(const T original[], T duplicate[], const short size)
{
  for (short i=0; i<size; i++)
  {
    duplicate[i]=original[i];
  }

  return;
}

//Description: Print_array will ouput every element (up to size number of
//  elements) in arr[] seperated by a single space.
//Pre: size must be greater than or equal to zero.
//Post: Every element (up to size number of elements) in arr will be
//  outputted seperated by a single space.
template <typename T>
void print_array(const T arr[], const short size)
{
  for (short i=0; i<size; i++)
  {
    cout<<arr[i]<<" ";
  }
}

#endif

