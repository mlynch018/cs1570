//Programmer: Midori Lynch             Date: 11/03/19
//File: hospital_room.h                Class: Section A
//Purpose: This file contians the hospital_room class for Dr. Nick's hospital
//  simulation program

#ifndef HOSPITAL_ROOM_H
#define HOSPITAL_ROOM_H

#include "x_rayer.h"
#include "patient.h"

using namespace std;

class hospital_room
{
  private:
    x_rayer the_machine;
    float gin;
  public:
    //Default constructor
    //Pre: None.
    //Post: All member varaibles of the hospital_room will be intialized.
    hospital_room(): gin(10) {}
    //Calls the_machine's charge_patient and apply functions
    //Pre: None.
    //Post: the_machine's charge patient and apply functions will be called;
    //  therefore changing the money and condition of pat.
    void admit(Patient & pat);
    //Overloads the insertion operator for the hospital_room class
    //Pre: None
    //Post: Outputs the status of hr to the cnosole, and the ostream
    //  passed in will be returned.
    friend ostream& operator<<(ostream& os, const hospital_room& hr);
};

#endif
