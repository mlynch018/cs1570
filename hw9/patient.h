//Programmer: Midori Lynch             Date: 11/03/19
//File: patient.h                      Class: Section A
//Purpose: This file contians the patient class for Dr. Nick's hospital
//  simulation program

#ifndef PATIENT_H
#define PATIENT_H

#include <string>

using namespace std;

const int MAX_MONEY=4000;
const int MAX_HEALTH=100;
const int MAX_NAME_SIZE=50;

class Patient
{
  private:
    float money;
    bool is_alive;
    int condition;
    string name;

    //Counts the number of names in the patient name file.
    //Pre: none.
    //Post: Returns the number of names in the patient name file.
    int count_patient_names() const;
    //Selects a random name from the patient name file.
    //Pre: num_names must be greater than or equal to zero.
    //Post: Returns a random patient name.
    string get_rand_name(const int num_names) const;
    //Updates is_alive based on the condition of the calling object
    //Pre: none.
    //Post: is_alive will be updated
    void kill();
  public:
    //Default constructor
    //Pre: None.
    //Post: All member variables of the patient will be initalized.
    Patient();
    //Add's the condition of the patient to val and calls kill()
    //Pre: None.
    //Post: Val will be added to patient and kill() will update is_alive
    void modify_health(const int val);
    //Reduces the money of the calling patient object by val
    //Pre: amt must be positive.
    //Post: the money of the calling patient object will be reduced by val.
    void pay_out(const float amt);
    //Overloads the insertion operator for the patient class.
    //Pre: None.
    //Post:Outputs the status of pat to the console, and the ostream
    //  passed in will be returned.
    friend ostream& operator<<(ostream& os, const Patient& pat);
    //Gets the condition of the calling patient object
    //Pre: None.
    //Post: returns the conditon of the calling patient object.
    int getCondition() const {return condition;}
};

#endif
