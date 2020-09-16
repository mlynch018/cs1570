/Programmer: Midori Lynch     Date: 09/01/19
//File: hw2.cpp                Class: Section A
//Purpose: computing patients' prescription doses using Dr. Riviera's formula

#include <iostream>
using namespace std;

int main()
{
  /*--------------------------DECLARATIONS-----------------------------*/
  const short MIN_TABLET_SALES=20;//aka Dr. Nick's constant
  const short TABLET_STRENGTH=250;
  short dosage;
  short age;
  short iq;
  short pills_per_day;//aka frequency
  short gender;
  float weight_in_kg;
  /*-----------------------GREETINGS AND INPPUT------------------------*/
  cout<<"Hello, Dr. Nick Riviera!"<<endl;
  cout<<"What is the patient's age? ";
  cin>>age;
  cout<<"What is the patient's weight (in kilograms)? ";
  cin>>weight_in_kg;
  cout<<"What is the patient's IQ? ";
  cin>>iq;
  cout<<"What is the patient's gender? "
    <<"Enter 1 for male and 0 for female: ";
  cin>>gender;
  cout<<"How many pills per day should the patient take? ";
  cin>>pills_per_day;

  /*---------------------COMPUTATIONS AND OUTPUT-----------------------*/
  dosage=static_cast<short>(((static_cast<float>(age))/iq)*
    ((weight_in_kg/pills_per_day)+1)*
    (((static_cast<float>(TABLET_STRENGTH))/1000)+gender)+
    MIN_TABLET_SALES);

  cout<<endl<<"Dr. Nick, for the inputs:"<<endl;
  cout<<"\tAge "<<age<<endl;
  cout<<"\tWeight "<<weight_in_kg<<" kg"<<endl;
  cout<<"\tIQ = "<<iq<<endl;
  cout<<"\tGender is "<<gender<<"  ( 1 -> male, 0 -> female )"<<endl;
  cout<<"\tFrequency "<<pills_per_day<<endl;
  cout<<"\tTablet Strength is "<<TABLET_STRENGTH<<" mg"<<endl<<endl;
  cout<<"The recommended dossage is "<<dosage<<" pills."<<endl;
  cout<<"Thank you for using the patient dosage calculator program."<<endl;
  return 0;
}

