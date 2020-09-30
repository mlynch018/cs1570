/Programmer: Midori Lynch             Date: 10/21/19
//File: diagnosis.h                    Class: CS1570 Section A
//Purpose: This file contains the templates and prototypes for the functions
//  used in Dr. Nick's automated doctor program.

#ifndef DIAGNOSIS_H
#define DIAGNOSIS_H

#include <iostream>

using namespace std;

void get_complaint(char complaint[], const short max_size);

short get_num_words(const char ntca[], const short max_size);

void output_n_rand_words(const char ntca[], const short max_rand_val,
  const short num_words);

void find_file_name(const char compalint[], char file[]);

#endif
