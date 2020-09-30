//Programmer: Midori Lynch             Date: 10/12/19
//File: sorting.cpp                    Class: Section A
//Purpose: This file contains the main function for Dr. Nick's
//         sorting algorithm evaluator program.

#include <iostream>
#include <cstdlib>

#include "nicks_sort.h"
#include "bubble_sort.h"
#include "sort.h"

using namespace std;

int main()
{
  /*-------------------------Declarations--------------------------*/

  //Seed the random number generator
  srand(42);

  //Constant variable declarations
  const short SIZE1=15;
  const int RAND_MIN1=5;
  const int RAND_MAX1=100;

  const short SIZE2=15000;
  const int RAND_MIN2=105;
  const int RAND_MAX2=15000;

  const short SORTING_TIMES=10;

  //Non-Constant variable Declarations
  int bubble_arr1[SIZE1];
  int nick_unsorted1[SIZE1];
  int nick_sorted1[SIZE1];

  int bubble_arr2[SIZE2];
  int nick_unsorted2[SIZE2];
  int nick_sorted2[SIZE2];

  //time related variables for part 2
  float start;
  float finish;
  float run_time;

  float nick_min;
  float nick_max;
  float nick_sum;
  float nick_avg;

  float bubble_min;
  float bubble_max;
  float bubble_sum;
  float bubble_avg;

  /*-------------------------------Part 1----------------------------*/

  //Initalize unsorted arrays
  populate_int_arr(bubble_arr1, SIZE1, RAND_MIN1, RAND_MAX1);
  populate_int_arr(nick_unsorted1, SIZE1, RAND_MIN1, RAND_MAX1);

  //Bubble sort
  cout<<"Part1: "<<endl;
  cout<<"Unsorted Bubble Sort Array: "<<endl;
  print_array(bubble_arr1, SIZE1);
  cout<<endl<<endl;

  bubble_sort(bubble_arr1, SIZE1);

  cout<<"Sorted Bubble Sort Array:"<<endl;
  print_array(bubble_arr1, SIZE1);
  cout<<endl<<endl;

  //Nick's sort
  cout<<"Unsorted Nick's Sort Array: "<<endl;
  print_array(nick_unsorted1, SIZE1);
  cout<<endl<<endl;

  nicks_sort(nick_unsorted1, nick_sorted1, SIZE1);

  cout<<"Sorted Nick's Sort Array: "<<endl;
  print_array(nick_sorted1, SIZE1);
  cout<<endl<<endl;

  /*-------------------------------Part 2----------------------------*/

  for (short i=0; i<SORTING_TIMES; i++)
  {
    populate_int_arr(bubble_arr2, SIZE2, RAND_MIN2, RAND_MAX2);
    copy_arr_data(bubble_arr2, nick_unsorted2, SIZE2);

    //for BUBBLE sort------------------------------------------
    start=clock();
    bubble_sort(bubble_arr2, SIZE2);
    finish=clock();
    run_time=(static_cast<float>(finish)-start)/CLOCKS_PER_SEC;

    if (i==0)//give min & max a value if they dont have one yet
    {
      bubble_min=run_time;
      bubble_max=run_time;
    }
    else//update min & max if necessary
    {

      if (run_time<bubble_min)
      {
        bubble_min=run_time;
      }
      if (run_time>bubble_max)
      {
        bubble_max=run_time;
      }

    }

    bubble_sum+=run_time;

    //for NICK'S sort------------------------------------------
    start=clock();
    nicks_sort(nick_unsorted2, nick_sorted2, SIZE2);
    finish=clock();
    run_time=(static_cast<float>(finish)-start)/CLOCKS_PER_SEC;

    if (i==0)//give min & max a value if they dont have one yet
    {
      nick_min=run_time;
      nick_max=run_time;
    }
    else//update min & max if necessary
    {

      if (run_time<nick_min)
      {
        nick_min=run_time;
      }
      if (run_time>nick_max)
      {
        nick_max=run_time;
      }

    }

    nick_sum+=run_time;


  }
  //Bubble sort results
  bubble_avg=bubble_sum/SORTING_TIMES;
  cout<<"Bubble sort Results:"<<endl;
  cout<<"Minimum sorting time: "<<bubble_min<<endl;
  cout<<"Maximum sorting time: "<<bubble_max<<endl;
  cout<<"Average sorting time: "<<bubble_avg<<endl<<endl;

  //Nick's sort results
  nick_avg=nick_sum/SORTING_TIMES;
  cout<<"Nick's sort Results:"<<endl;
  cout<<"Minimum sorting time: "<<nick_min<<endl;
  cout<<"Maximum sorting time: "<<nick_max<<endl;
  cout<<"Average sorting time: "<<nick_avg<<endl<<endl;

  return 0;
}

