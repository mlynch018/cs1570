//Programmer: Midori Lynch             Date: 10/12/19
//File: sorting.cpp                    Class: Section A
//Purpose: This file contains the template functions used in Dr. Nick's
//         sorting algorithm.

#ifndef NICKS_SORT_H
#define NICKS_SORT_H

using namespace std;

//Description: The swaps function will swap two values.
//Pre: The assignment operator must be defined for type U.
//Post: The values of num1 and num2 will be swapped.
template <typename U>
void swaps(U & num1, U & num2)
{
  U temp = num1;
  num1 = num2;
  num2 = temp;

  return;
}

//Description: This function will place val in the sorted array in the
//  position that makes the entire array sorted in increasing order.
//Pre: The sorted_size must be at least one, and sorted must contain at
//  leat one element.
//Post: Val will added to the sorted array and put in the position that
//  makes the entire array sorted.
template <typename Y>
void putInPlace(const Y val, Y sorted[],const short sorted_size)
{
  //DECLARATIONS
  bool placeFound = false;
  short i = sorted_size;
  //NOTE: sorted_size was the size of the sorted array before this new
  //value was added
  //so, this will add val onto the end of the sorted array
  sorted[sorted_size] = val;

  //if val is the biggest number then its place has already been found
  if (sorted[sorted_size] > sorted[sorted_size - 1])
  {
    placeFound = true;
  }

  //keeps swapping values from right to left until val is sorted
  //i>=1 b/c maximum number of swaps will be equal to sorted_size if val
  //is smallest number and you don't want to walk off the array
  while (!placeFound && i >= 1)
  {
    swap(sorted[i - 1], sorted[i]);

    i--; //decrease before if statement b/c val will now be in pos i-1

    if (sorted[i] >= sorted[i - 1] && sorted[i] <= sorted[i + 1])
    {
      placeFound = true;
    }
  }

}
//Description: nicks_sort will sort the unsorted array in increasing order
//  and place the results in sorted[] by using Dr. Nick's algorithm.
//Pre: sorted[] must be greater than or equal to the size of unsorted.
//  size must be greater than zero.
//Post: sorted[] will contain the values of unsorted[] sorted in
//  increasing order.
template <typename T>
void nicks_sort(const T unsorted[], T sorted[],const short size)
{
  //for the first element, automatically put it into the other array
  //since you cant sort only one thing
  sorted[0] = unsorted[0];

  for (short i = 1; i < size ; i++)
  {
    putInPlace(unsorted[i], sorted, i);
  }
}

#endif
