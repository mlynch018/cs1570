//Programmer: Midori Lynch             Date: 11/03/19
//File: patient.cpp                    Class: Section A
//Purpose: This file contians the function definitions for the patient class
//  used for Dr. Nick's hospital simulation program

#include "patient.h"

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

Patient::Patient()
{
  money=rand()%(MAX_MONEY+1);
  condition=rand()%(MAX_HEALTH+1);
  name=get_rand_name(count_patient_names());
  kill();
}

int Patient::count_patient_names() const
{
  char name[MAX_NAME_SIZE];
  int i=0;

  ifstream in;
  in.open("names.dat");

  while (in>>name)
    i++;

  in.close();

  return i;
}

string Patient::get_rand_name(const int num_names) const
{
  int rand_num=rand()%num_names;
  int i=-1;
  string name;

  ifstream in;
  in.open("names.dat");

  while (i!=rand_num)
  {
    in>>name;
    i++;
  }

  return name;
}

void Patient::kill()
{
  if (condition<=0)
  {
    is_alive=false;
  }
  else
  {
    is_alive=true;
  }
  return;
}

void Patient::modify_health(const int val)
{
  condition+=val;
  kill();
  return;
}

void Patient::pay_out(const float amt)
{
  money-=amt;
  return;
}

ostream& operator<<(ostream& os, const Patient& pat)
{
  os<<pat.name<<" has $"<<pat.money <<"."<<endl;
  os<<pat.name<<"'s health is at "<<pat.condition<<", and they "<<
    (pat.is_alive? "are " : "are not ")<<"alive.";

  return os;
}
