//Programmer: Midori Lynch             Date: 11/03/19
//File: x_rayer.h                      Class: Section A
//Purpose: This file contians the x_rayer class for Dr. Nick's hospital
//  simulation program

#ifndef X_RAYER_H
#define X_RAYER_H

#include "patient.h"

#include <iostream>

using namespace std;

class x_rayer
{
  private:
    float cost_per_use;
    short num_uses;
  public:
    //Default constructor
    //Pre: None.
    //Post: All member variables of the x_rayer will be initalized.
    x_rayer(): cost_per_use(550), num_uses(0){}
    //This function charges the patient, pat, the cost of use of the
    //   machine.
    //Pre: None.
    //Post: pat's money will be decreased by cost_per_use.
    void charge_patient(Patient & pat) const;
    //This function halves the condition of pat 10% of the time, and
    //  increases num_uses by one.
    //Pre: None.
    //Post: num_uses will be increased, and conditon of pat may be altered.
    void apply (Patient & pat);
    //Overloads the insertion operator for the x_rayer class.
    //Pre: none.
    //Post: Ouputs the status of xr to the console, and the ostream
    //  passed in will be returned.
    friend ostream& operator <<(ostream& os, const x_rayer& xr);
};
