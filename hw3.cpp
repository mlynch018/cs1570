/Programmer: Midori Lynch     Date: 09/07/19
//File: hw3.cpp                Class: CS1570 Section A
//Purpose: To ask questions of a potential "patient" and then
//give recommendations on what the person is to do

#include <iostream>
using namespace std;
int main()
{
  /*--------------------------DECLARATIONS-----------------------------*/
  const short NO_MONEY=0;
  const float SURGERY_COST=129.95;
  const short MIN_HUMAN_AGE=2;
  const short MAX_HUMAN_AGE=110;
  const short LEGAL_SURGERY_AGE=21;
  const short MIN_ELDERLY_AGE=66;
  string patientsName;
  float patientsMoney;
  short patientsAge;
  char filedMalpracticeResponse;
  bool filedMalpractice;
  short numSurgeries;
  float totalSurgeryCost;
  float patientsMoneyAfterSurgeryCost;
  short numMoreSurgeries;
  short numAffordableSurgeries;
  char anotherPatient;
  /*---------------------DECIMAL FORMATTING----------------------------*/
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  /*------------------GREETINGS, INPPUT, AND OUTPUT--------------------*/
  do
  {
    filedMalpractice=false;/*automatically assume no because
    patients who are at least MIN_ELDERLY_AGE won't be asked if they
    filed a suit and will be asked to have surgeries regardless*/
    numMoreSurgeries=0;
    numAffordableSurgeries=0;
    /*These varaibles are initalized here rather than the top
    b/c if do while loop runs more than once the logic
    could get messed up if you don't reset them*/
    /*All of the other variables get initalized below if necessary*/
    cout<<"Hello, welcome to Dr. Nick's office!"<<endl;
    cout<<"What is your name? ";
    cin>>patientsName;
    cout<<"Hi, "<<patientsName<<", how much money do you have with you? $";
    cin>>patientsMoney;
    if (patientsMoney<=NO_MONEY)
    { //condition for being in debt or having no money
      cout<<"Leave the premises immediately...and have a good day. NEXT.";
      cout<<endl;
    }
    else if (patientsMoney>NO_MONEY && patientsMoney<SURGERY_COST)
    {
      //patients with money who can't afford surgery
      cout<<"Please come back when you have at least $"<<SURGERY_COST<<endl;
    }
    else
    {
      do
      {
        cout<<"How old are you, "<<patientsName<<"? ";
        cin>>patientsAge;
     //check to make sure the human is old enough to type and not
        //unrealistically old.
      } while (patientsAge<MIN_HUMAN_AGE || patientsAge>MAX_HUMAN_AGE);

      if (patientsAge<LEGAL_SURGERY_AGE)//make sure patient is legal age
      {
        cout<<"Please leave. You're too youg!"<<endl;
      }
      else //anyone LEGAL_SURGERY_AGE or over including elders
      {
        //check for malpractice suits filed
        if(patientsAge>=LEGAL_SURGERY_AGE && patientsAge<MIN_ELDERLY_AGE)
        {
          cout<<patientsName;
          cout<<", have you ever filed for a malpractice suit(Y/N)? ";
          cin>>filedMalpracticeResponse;
          if (filedMalpracticeResponse=='Y')
          {
            filedMalpractice=true;
            cout<<"I'm sorry, we're closed now!"<<endl;
          }
        }
        //Asks patients who haven't filed suits
        //or are at least MIN_ELDERLY_AGE to have surgerys
        if (filedMalpractice==false)
        {
          cout<<endl<<"Surgeries cost $"<<SURGERY_COST<<" each."<<endl;
          cout<<"How many surgeries do you want, "<<patientsName<<"? ";
          cin>>numSurgeries;
          totalSurgeryCost=numSurgeries*SURGERY_COST;
          patientsMoneyAfterSurgeryCost=patientsMoney-totalSurgeryCost;
          //condition for patients w/SURGERY_COST or more left over
          if (patientsMoneyAfterSurgeryCost>=SURGERY_COST)
          {

            //checks to see if patient can affor more surgeries
            while (patientsMoneyAfterSurgeryCost>=SURGERY_COST)
            {
              numMoreSurgeries++;
              patientsMoneyAfterSurgeryCost-=SURGERY_COST;
            }
            cout<<endl<<patientsName<<", ";
            cout<<"Your surgeries will cost $"<<totalSurgeryCost<<endl;
            cout<<"You can purchase "<<numMoreSurgeries
              <<" more surguries today!"<<endl;
            cout<<"Come on in!"<<endl;
          }
          else if (patientsMoneyAfterSurgeryCost>NO_MONEY)
          {//condition for patients who chose the right amount of surgeries
            //they have money, but not enough for more surgeries
            cout<<"Come on in!"<<endl;
          }
          else
          { //condition for patients who chose more surgeries than they
            //can afford
            while (patientsMoney>=SURGERY_COST)
            {
              numAffordableSurgeries++;
              patientsMoney-=SURGERY_COST;
            }
            cout<<"You can afford "<<numAffordableSurgeries<<" surgeries.";
            cout<<endl;
            cout<<"Come on in!"<<endl;
          }
         }
        }
      }
    }
    cout<<endl<<"Anybody else there(Y/N)? ";
    cin>>anotherPatient;
    cout<<endl;
    }while(anotherPatient=='Y'||anotherPatient=='y');
    cout<<"Dr. Nick's receptionist software will be closing now. ";
    cout<<"Goodbye."<<endl;
    return 0;
}
