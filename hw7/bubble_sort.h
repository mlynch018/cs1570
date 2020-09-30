//Programmer: Midori Lynch             Date: 10/12/19
//File: sorting.cpp                    Class: Section A
//Purpose: This file contains the template functions used in the bubble
//  sort sorting algorithm.

#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

//Description: The swapvals function will swap two values.
//Pre: The assignment operator must be defined for type U.
//Post: The values of num1 and num2 will be swapped.
template <typename U>
void swapvals(U & num1, U & num2)
{
  U temp = num1;
  num1 = num2;
  num2 = temp;

  return;
}

//Description: Bubble_sort swaps adjacent elements until unsorted[]
//  is sorted in increasing order.
//Pre: Size must be greater than or equal to zero.
//Post: The values of unsorted[] will now be sorted in increasing order.
template <typename T>
void bubble_sort(T unsorted[],const short size)
{
  short i = 0;
  short j = 0;
  bool any_swaps=false;
  bool is_sorted = false;


  //i<size-1 b/c of swapping
  //if
  while (i < size - 1 && !is_sorted)
  {
    any_swaps = false; //assume no swaps have occured yet

    //j<size-1-i b/c i number of elements will be the biggest/sorted at the
    //end of the array since all unsorted adjacent elements are compared
    //every time through
    for (j = 0; j < (size - 1 - i); j++)
    {
      if (unsorted[j] > unsorted[j + 1])
      {
        swap(unsorted[j], unsorted[j + 1]);
        any_swaps = true;
      }
    }

    //if no swaps occur in one pass of whole array then it is sorted
    if (!any_swaps)
    {
      is_sorted = true;
    }

    i++;
  }

}

#endif
