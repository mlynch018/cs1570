//Programmer: Midori Lynch             Date: 11/03/19
//File: x_rayer.cpp                    Class: Section A
//Purpose: This file contians the function definitions for the x_rayer class
//  used for Dr. Nick's hospital simulation program


#include "x_rayer.h"
#include <iostream>

using namespace std;

void x_rayer::charge_patient(Patient & pat) const
{
  pat.pay_out(cost_per_use);
  return;
}

void x_rayer::apply(Patient & pat)
{
  int half_condition=(pat.getCondition()/2);
  int rand_num=(rand()%10);

  if (rand_num==0)
  {
    pat.modify_health((-1*half_condition));
  }

  charge_patient(pat);

  num_uses++;

  return;
}

ostream& operator <<(ostream& os, const x_rayer& xr)
{
  cout<<"x_rayer cost: $"<<xr.cost_per_use<<endl;
  cout<<"x_rayer number of uses: "<<xr.num_uses<<endl;

  return os;
}
