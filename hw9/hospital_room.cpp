//Programmer: Midori Lynch             Date: 11/03/19
//File: hospital_room.cpp              Class: Section A
//Purpose: This file contians the function definitions for the hospital_room
//  class used for Dr. Nick's hospital simulation program

#include "hospital_room.h"

#include <iostream>

using namespace std;

void hospital_room::admit(Patient & pat)
{
  the_machine.apply(pat);
  return;
}

ostream& operator<<(ostream& os, const hospital_room& hr)
{
  os<<"The room contains "<<hr.gin<<" ounces of gin"<<endl;
  os<<hr.the_machine;
  return os;
}
