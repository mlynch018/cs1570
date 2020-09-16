//Programmer: Midori Lynch     Date: 09/18/19
//File: hw4.cpp                Class: Section A
//Purpose: emulate the operation of Dr. Nick's vending machines

#include <iostream>
using namespace std;

int main()
{
  /*--------------------------DECLARATIONS-----------------------------*/
  //organ prices
  const float EYEBALLS_PRICE=3.35;
  const float SPLEEN_PRICE=2.75;
  const float LIVER_PRICE=14.58;
  const float APPENDIX_PRICE=0.50;
  const float BRAINS_PRICE=7.85;
  const float EAR_LOBES_PRICE=13.45;

  //organ weights
  const float EYEBALLS_WGT=2.3;
  const float SPLEEN_WGT=5.6;
  const float LIVER_WGT=3;
  const float APPENDIX_WGT=1.2;
  const float BRAINS_WGT=0.4;
  const float EAR_LOBES_WGT=10;

  //pan weights
  const short XSMALL_PAN_WGT=1;
  const short SMALL_PAN_WGT=2;
  const short MEDIUM_PAN_WGT=5;
  const short LARGE_PAN_WGT=10;
  const short XLARGE_PAN_WGT=15;

  //organ cases
  const short EYEBALLS_CASE=1;
  const short SPLEEN_CASE=2;
  const short LIVER_CASE=3;
  const short APPENDIX_CASE=4;
  const short BRAINS_CASE=5;
  const short EAR_LOBES_CASE=6;
  const short QUIT_CASE=7;
  const short NO_CASE=0;

  //non-constant variables
  int user_choice;
  float user_bill=0;
  float vended_organs_total_wgt;
  float user_payment_amt;
  float user_change;
  float min_pan_wgt;
  bool quit;
  /*-----------------------GREETINGS AND INPPUT------------------------*/
  do
  {
    //(re)set necessary  vars to starting values
    quit=false;
    vended_organs_total_wgt=0;

    //print menu and get user's choice
    cout<<"Welcome to Dr. Nick's vending machine."<<endl;
    cout<<"Here are your choices: "<<endl<<endl;

    cout<<"1.) eyeballs $"<<EYEBALLS_PRICE<<endl
      <<"2.) spleen $"<<SPLEEN_PRICE<<endl
      <<"3.) liver $"<<LIVER_PRICE<<endl
      <<"4.) appendix $"<<APPENDIX_PRICE<<endl
      <<"5.) brains $"<<BRAINS_PRICE<<endl
      <<"6.) ear lobes $"<<EAR_LOBES_PRICE<<endl
      <<"7.) quit"<<endl<<endl;

    cout<<"Enter the integer corresponding to your choice: ";
    cin>>user_choice;
    cout<<endl;
    /*---------------------COMPUTATIONS AND OUTPUT-------------------*/

    //compute bill and total weight of vended organs
    //Also, outputs what organs the user will recieve
    switch (user_choice)
    {
      case EYEBALLS_CASE:

        user_bill=EYEBALLS_PRICE;
        vended_organs_total_wgt+=EYEBALLS_WGT;
        cout<<"You will recieve eyeballs."<<endl;
        break;

      case SPLEEN_CASE:

        user_bill=SPLEEN_PRICE;
        vended_organs_total_wgt+=SPLEEN_WGT;
        cout<<"You will recieve a spleen."<<endl;
        break;

      case LIVER_CASE:

        user_bill=LIVER_PRICE;
        vended_organs_total_wgt+=LIVER_WGT;
        cout<<"You will recieve a liver."<<endl;
        break;

      case APPENDIX_CASE:

        user_bill=APPENDIX_PRICE;
        vended_organs_total_wgt+=APPENDIX_WGT;
        cout<<"You will recieve an appendix."<<endl;
        //falls through

      case BRAINS_CASE:

        user_bill=BRAINS_PRICE;
        vended_organs_total_wgt+=BRAINS_WGT;
        cout<<"You will recieve brains."<<endl;
        //falls through

      case EAR_LOBES_CASE:

        user_bill=EAR_LOBES_PRICE;
        vended_organs_total_wgt+=EAR_LOBES_WGT;
        cout<<"You will recieve ear lobes."<<endl;
        break;

      case QUIT_CASE:

        quit=true;
        break;
      default:
        cout<<"Input invalid. Try again."<<endl<<endl;
    }

    /*only prompt for payment and state weight if the
    user chooses a valid choice that wasn't quit */
    if (quit==false && user_choice<QUIT_CASE && user_choice>NO_CASE)
    {
      //Output bill and prompt for payment until user enters a valid amount
      do
      {
        cout<<endl<<"Your cost is $"<<user_bill<<endl;
        cout<<"Enter your payment amount: $";
        cin>>user_payment_amt;

        if (user_payment_amt<user_bill)
        {
          cout<<"ERROR! Insufficent payment. Try again."<<endl;
        }

      }while(user_payment_amt<user_bill);

      //compute change
      user_change=user_payment_amt-user_bill;
      cout<<endl<<"Your change is $"<<user_change<<endl;

      //Output organ weight and proper pan size
      cout<<"Your organs weigh "<<vended_organs_total_wgt
        <<" lb(s)."<<endl<<endl;

      //calculate pan size
      if (vended_organs_total_wgt>LARGE_PAN_WGT)
      {
        min_pan_wgt=XLARGE_PAN_WGT;
      }
      else if (vended_organs_total_wgt>MEDIUM_PAN_WGT)
      {
        min_pan_wgt=LARGE_PAN_WGT;
      }
      else if (vended_organs_total_wgt>SMALL_PAN_WGT)
      {
        min_pan_wgt=MEDIUM_PAN_WGT;
      }
      else if (vended_organs_total_wgt>XSMALL_PAN_WGT)
      {
        min_pan_wgt=SMALL_PAN_WGT;
      }
      else
      {
        min_pan_wgt=XSMALL_PAN_WGT;
      }

      cout<<"Your choice is coming. "<<endl;
      cout<<"You better have a "<<min_pan_wgt<<" lb. pan ready";
      cout<<endl<<endl;
    }
  }while(!quit);

  cout<<"Thank you for using Dr. Nick's vending machine."<<endl;
  return 0;
}

