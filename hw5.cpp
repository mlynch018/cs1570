/Programmer: Midori Lynch     Date: 09/25/19
//File: hw5.cpp                Class: Section A
//Purpose: Translate an alphabetical character into
//         morse code, an ASCII value, or a different case
//         depening on the user's choice

#include <iostream>
using namespace std;

//constant variables
const int MIN_LOWER_ASCII_VAL=97;
const int MIN_UPPER_ASCII_VAL=65;
const int CASE_DIFFERENCE=32;
const int MAX_LOWER_ASCII_VAL=122;
const int MAX_UPPER_ASCII_VAL=90;

//function protoypes

//Description: Displays a greeting to the screen
//Pre: None
//Post: Will output a message to the screen
void greetings();

//Description: displays a menu to the user and returns their menu choice
//Pre: None
//Post: Outputs a message to the screen
char present_menu();

//Description: Goes to the function that completes the desired task
//  determined by the user's menu choice and returns if the user
//  wants to quit
//Pre: None (the other methods will error trap if alpha isn't alphabetical
//  and if char isn't one of the menu options option_handler() will reprompt
//Post: alpha and/or option1_chosen could be changed.
//  A message might be outputed to the screen
bool option_handler(const char option, char & alpha, bool & option1_chosen);

//Description: Gets an alphabetic character from the user
//Pre: None
//Post: A message is outputted to the screen, and an alphabetical
//  character is returned based on the user's input.
char get_input_from_user();

//Description: Displays an error message to the screen that the
//  user has not enter a character yet
//Pre: None
//Post: Outputs a message to the screen
void error_message();

//Description: Outputs the morse code equivilant of alpha to the screen
//Pre: alpha must be alphabetical
//Post: Outputs a message to the screen
void output_morse(const char alpha);

//Description: Outputs the ASCII value of alpha to the screen
//Pre: alpha must be alphabetical
//Post: Outputs a message to the screen
void output_ascii(const char alpha);

//Description: Changes the case of alpha
//Pre: alpha must be alphabetical
//Post: changes the value of alpha
void change_case(char & alpha);

//Description: Dispalys an exit greeting to the screen
//Pre: None
//Post: Will display a message to the screen
void goodbyes();

//main
int main()
{
  /*--------------------------DECLARATIONS-----------------------------*/
  char option;
  bool quit;
  char alpha;
  bool option1_chosen=false;
  /*---------------------------GREETINGS------------------------------*/
  greetings();
  /*---------------------INPUT AND COMPUTATIONS-----------------------*/
  do
  {
    option=present_menu();
    quit=option_handler(option,alpha,option1_chosen);
  }while(!quit);
  /*-----------------------------OUTPUT-------------------------------*/
  goodbyes();

  return 0;
}

//The greetings() greets the user
void greetings()
{
  cout<<"Hello, welcome to Dr. Nick's character translator!"<<endl<<endl;
  return;
}

//The present_menu() outputs the menu
//and returns the menu option chosen by the user
char present_menu()
{
  char choice;

  cout<<"Translate"<<endl;
  cout<<"---------"<<endl<<endl;
  cout<<"1. Enter a character (alphabetical)"<<endl;
  cout<<"2. Morse code equivalent"<<endl;
  cout<<"3. ASCII value"<<endl;
  cout<<"4. Change case"<<endl;
  cout<<"5. Kwit"<<endl<<endl;

  cout<<"Enter the integer corresponding to your choice: ";
  cin>>choice;
  cout<<endl;

  return choice;
}

//Completes necessary changes to alpha depending on the user's menu choice
//and returns if the user wants to quit
bool option_handler(const char option, char & alpha, bool & option1_chosen)
{
  bool quit=false;

  switch (option)
  {
    case '1':
      alpha=get_input_from_user();
      option1_chosen=true;
      break;

    case '2':
      if (option1_chosen)
        output_morse(alpha);
      else
        error_message();
      break;

    case '3':
      if (option1_chosen)
        output_ascii(alpha);
      else
        error_message();
      break;

    case '4':
      if (option1_chosen)
        change_case(alpha);
      else
        error_message();
      break;

    case '5':
      quit=true;
      break;

    default:
      cout<<"You have entered an invalid option.";
      cout<<"Try again."<<endl<<endl;
  }

  return quit;
}

//gets a character from the use to use in the remaining menu options
char get_input_from_user()
{
  char user_char;

  do
  {
    cout<<"Enter a character: ";
    cin>>user_char;
    cout<<endl;

    if (!((user_char>=MIN_LOWER_ASCII_VAL && user_char<=MAX_LOWER_ASCII_VAL)
      || (user_char>=MIN_UPPER_ASCII_VAL && user_char<=MAX_UPPER_ASCII_VAL)))
    {
      cout<<"The character must be alphabetical."<<endl;
    }

  }
  while(!((user_char>=MIN_LOWER_ASCII_VAL && user_char<=MAX_LOWER_ASCII_VAL)
    ||(user_char>=MIN_UPPER_ASCII_VAL && user_char<=MAX_UPPER_ASCII_VAL)));

  return user_char;
}

//outputs alpha's morse code value
void output_morse(const char alpha)
{
  cout<<"Morse code for "<<alpha<<": ";

  switch (alpha)
  {
    case 'a':
    case 'A':
      cout<<".-"<<endl;
      break;
    case 'b':
    case 'B':
      cout<<"-..."<<endl;
      break;
    case 'c':
    case 'C':
      cout<<"-.-."<<endl;
      break;
    case 'd':
    case 'D':
      cout<<"-.."<<endl;
      break;
    case 'e':
    case 'E':
      cout<<"."<<endl;
      break;
    case 'f':
    case 'F':
      cout<<"..-."<<endl;
      break;
    case 'g':
    case 'G':
      cout<<"--."<<endl;
      break;
    case 'h':
    case 'H':
      cout<<"...."<<endl;
      break;
    case 'i':
    case 'I':
      cout<<".."<<endl;
      break;
    case 'j':
    case 'J':
      cout<<".---"<<endl;
      break;
    case 'k':
    case 'K':
      cout<<"-.-"<<endl;
      break;
    case 'l':
    case 'L':
      cout<<".-.."<<endl;
      break;
    case 'm':
    case 'M':
      cout<<"--"<<endl;
      break;
    case 'n':
    case 'N':
      cout<<"-."<<endl;
      break;
    case 'o':
    case 'O':
      cout<<"---"<<endl;
      break;
    case 'p':
    case 'P':
      cout<<".--."<<endl;
      break;
    case 'Q':
    case 'q':
      cout<<"--.-"<<endl;
      break;
    case 'r':
    case 'R':
      cout<<".-."<<endl;
      break;
    case 's':
    case 'S':
      cout<<"..."<<endl;
      break;
    case 't':
    case 'T':
      cout<<"-"<<endl;
      break;
    case 'u':
    case 'U':
      cout<<"..-"<<endl;
      break;
    case 'v':
    case 'V':
      cout<<"...-"<<endl;
      break;
    case 'w':
    case 'W':
      cout<<".--"<<endl;
      break;
    case 'x':
    case 'X':
      cout<<"-..-"<<endl;
      break;
    case 'y':
    case 'Y':
      cout<<"-.--"<<endl;
      break;
    case 'z':
    case 'Z':
      cout<<"--.."<<endl;
      break;
  }

  cout<<endl;
  return;
}

//outputs the ascii value of alpha
void output_ascii(const char alpha)
{
  int ascii_val;
  ascii_val=static_cast<int>(alpha);
  cout<<"The ASCII value of \'"<<alpha<<"\' is "<<ascii_val<<"."
    <<endl<<endl;
  return;
}

//changes the case of the character
void change_case(char & alpha)
{
  int ascii_val=static_cast<int>(alpha);
  int alpha_new_ascii_val;

  //checks to see if the letter is upper case
  if (ascii_val>=MIN_UPPER_ASCII_VAL && ascii_val<=MAX_UPPER_ASCII_VAL)
  {
    alpha_new_ascii_val=ascii_val+CASE_DIFFERENCE;
  }
  else //condition for lower case letters
  {
    alpha_new_ascii_val=ascii_val-CASE_DIFFERENCE;
  }

  alpha=static_cast<char>(alpha_new_ascii_val);

  return;
}

//outputs an error message if the user tries to chose one
//of the menu options that requires a char before inputting a char
void error_message()
{
  cout<<"You have not entered a character yet."<<endl;
  cout<<"Please enter a character, then try again."<<endl;
  cout<<endl;
  return;
}

//The goodbyes() tells the user goodbye
void goodbyes()
{
  cout<<"Thank you for using Dr. Nick's character translator. ";
  cout<<endl<<"Have a nice day!"<<endl;
  return;
}
