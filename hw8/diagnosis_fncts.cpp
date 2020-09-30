/Programmer: Midori Lynch             Date: 10/21/19
//File: diagnosis_fncts.cpp            Class: CS1570 Section A
//Purpose: This file contains the function definitions for the functions
//  used in Dr. Nick's automated doctor program.

#include "diagnosis.h"

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>

using namespace std;

void get_complaint(char complaint[], const short max_size)
{
  char c;
  short i=0;

  cin.get(c);
  while (c!='\n' && i<max_size)
  {
    complaint[i]=c;
    cin.get(c);
    i++;
  }

  complaint[i]='\0';

  return;
}
short get_num_words(const char ntca[], const short max_size)
{
  short i=0;
  short num_words=0;
  char c;

  c=ntca[i];
  while (c!='\0' && i<max_size)
  {
    if (ntca[i]==' ')
    {
      num_words++;
    }
    i++;
    c=ntca[i];
  }

  //if there is at least one word, i will be greater than zero. If there is
  //one or more words, the last word will be marked by a period or new line
  //character not a space so it wouldn't have gotten included above.
  //if there is zero words (i==0) then we want to return 0;
  if (i>0)
  {
    num_words++;
  }

  return num_words;
}


void output_n_rand_words(const char ntca[], const short max_rand_val,
  const short num_words)
{
  int max_rand=static_cast<int>(max_rand_val);
  int rand_val;
  short pos;
  short i=0;
  short space_num=0;
  char c=ntca[i];
  char c2;

  for (short j=0; j<num_words; j++)
  {
    i=0;
    pos=0;
    space_num=0;
    c=ntca[i];

    rand_val=rand()%max_rand;//0 to max_rand_val-1
    //0 represents the first word, and all other nums represent the word
    // after the nth space

    if (rand_val==0)
    {
      pos=0;
    }
    else
    {
      while (space_num!=(rand_val))
      {
        c=ntca[i];

        if (c==' ')
        {
          space_num++;
          pos=i;
        }
        i++;
      }
    }

      //pos will be position of the space before the desired word, but we dont
      //want to print the space before the word. We want to start at the first
      //letter of the word. But, if pos is zero, there should not be a space
      //before the first word
      if(pos!=0)
        pos++;

      c2=ntca[pos];

      while (c2!=' ' && c2!='\0')
      {
        //I don't want to output any puncuation the word has unless it's a
        //single quote
        if (!ispunct(c2) || c2=='\'')
        {
          cout<<c2;
        }
        pos++;
        c2=ntca[pos];
      }


   if (j!=(num_words-1))
     cout<<" ";

   }
  return;
}

void find_file_name(const char complaint[], char file[])
{
  char word[20];
  char file1[20]={'h','e','a','d','\0'};
  int i=0;
  int pos=0;

  while (complaint[i]!='\0')
  {
    if (complaint[i]==' ' || complaint [i+1]=='\0')
    {
      if (complaint[i+1]=='\0')
      {
        word[pos]=complaint[i];
      }

      if (strcmp(word,file1)==0)
        cout<<"Yay"<<endl;

      for (int j=0; j<=pos; j++)
      {
        word[j]='\0';
      }
      pos=0;
    }
    else
    {
      word[pos]=complaint[i];
      pos++;
    }
    i++;
  }

}
