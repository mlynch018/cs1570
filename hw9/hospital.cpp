//Programmer: Midori Lynch             Date: 11/03/19
//File: hospital.cpp                   Class: Section A
//Purpose: This file contians the driver for Dr. Nick's hospital
//  simulation program

#include <iostream>
#include <cstdlib>

#include "x_rayer.h"
#include "patient.h"
#include "hospital_room.h"

using namespace std;

int main()
{
  /*---------------------SEEDING RANDOM NUMBER GENERATOR-----------------*/
  srand(time(NULL));

  /*---------------------DECLARATIONS-----------------------------------*/
  const int num_times_in_room=5;

  hospital_room hr;
  Patient p1;
  Patient p2;
  Patient p3;

  /*----------------COMPUTAIONS AND OUTPUT------------------------------*/
  cout<<"Hospital room 1: "<<endl<<hr<<endl;

  cout<<"Patient 1 Status: "<<endl<<p1<<endl<<endl;
  cout<<"Patient 2 Status: "<<endl<<p2<<endl<<endl;
  cout<<"Patient 3 Status: "<<endl<<p3<<endl<<endl;

  for (int i=1; i<=num_times_in_room; i++)
  {
    hr.admit(p1);
  }

  cout<<"After admitting patient 1 to hospital room 1: "<<endl;
  cout<<"Hospital room 1: "<<endl<<hr<<endl;

  cout<<"Patient 1 Status: "<<endl<<p1<<endl<<endl;
  cout<<"Patient 2 Status: "<<endl<<p2<<endl<<endl;
  cout<<"Patient 3 Status: "<<endl<<p3<<endl<<endl;

  return 0;
}
