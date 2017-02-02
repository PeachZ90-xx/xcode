/*
  main.cpp
  Warm up Jackpot
  Object Oriented Programming
 
  Created by Alan Trevino De Arcos on 8/26/14.
  Copyright (c) 2014 Alan Trevino. All rights reserved.
*/

#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <unistd.h> //this is the mac time header.
using namespace std;

//other programs
void Start();
void GetResults();
void end();
void easteregg();


//this was the old global stuff. Not yet removed.
int i, j;


//global stuff!!!
int life, maxrand;
char c;
string answer;
double pot [3];
double guess[3];

int main(int argc, const char * argv[])
{

    //if ((answer == "no") || (answer == "No")) //This will end the program
    //{
    //  return 0;
    //}
    
    cout << "===============================================\n";
    cout << "==================Jackpot Game=================\n";
    cout << "===============================================\n\n";
    sleep (1);
    cout << "The goal of this game is to guess the three (3) winning numbers.\n";
    sleep (1);
    cout << "I will tell you if the numbers are too big or too\n";
    cout << "small compared to the winning numbers!\n";
    sleep(1);
    cout << "You will only have five (5) lives to get the ";
    cout << "numbers correct. Look out for easter eggs. =]\n\n\n";
    sleep(3);
    
    //starts game
    Start();
    
    return 0;
}



//************************************THIS IS THE START OF THE GAME!!!
void Start()
{
    //i=0;
    //j=0;
    life = 0;
    maxrand=6;
    
    //select difficulty
    cout << "These are the different levels:\n";
    sleep(2);
    cout << "1 - Easy [0-15]\n";
    sleep(1);
    cout << "2 - Mediun [0-50]\n";
    sleep(1);
    cout << "3 - Hard [0-100]\n";
    sleep(1);
    cout << "4 - Extreme [0-1000]\n";
    sleep(2);
    cout << "Please choose a difficulty.\n";
    
    //user input
    cin >> c;
    cout << endl;
    
    
    
    switch (c){
        case '1':
            maxrand = 15;
            break;
        case '2':
            maxrand = 50;
            break;
        case '3':
            maxrand = 100;
            break;
        case '4':
            maxrand = 1000;
            break;
        case '5':
            easteregg();
            break;
        default:
            exit(0);
        break;
    }
    
    
    life = 5;
    srand((unsigned)time(NULL)); //init rand() function
    //j=rand() % maxrand; //j gets a random vaulue
    
    //winning numbers!!!
    pot[0]=rand() % maxrand;
    pot[1]=rand() % maxrand;
    pot[2]=rand() % maxrand;
    
    GetResults();
}



//**********************************THIS IS THE GUESSING PART!!!
void GetResults()
{
   
    
    //this section is for POT[0]
    
    //This is the code for when they lose ALL THE LIVES!!!
    if (life<=0)
    {
        cout << "You have run out of lives.\n\n";
        cout << "It was a pleasure!\n";
        sleep(3);
        system("clear");
        
        //repeat?
        end();
    }
    
    
    cout << "This is the first number guess.\n";
    cout << "Please choose a number: \n";
    cin >> guess[0];
    
    if ((guess[0]>maxrand) || (guess<0))
    {
        cout << "\n\nYou need to choose a number between 0 and" << maxrand;
        sleep(2);
        cout << "\n\nQuit fooling around fool!!!\n";
        GetResults();
    }
    
    if (guess[0]==pot[0])
    {
        sleep(5);
        cout << "Great job! You are correct!\n";
        sleep(1);
        cout << pot[0] << " was the number I was looking for.\n";
        
    }
    
    else if (guess[0]>pot[0])
    {
        cout << "\nOh, you overshot it.\n";
        life--;
        sleep(1);
        cout << "You have " <<life << " lives remaining.\n\n";
        
        GetResults();
    }
    
    else if(guess[0]<pot[0])
    {
        cout << "\nOh, you went too small.\n";
        life--;
        sleep(1);
        cout << "You have " <<life <<" lives remaining.\n\n";
        GetResults();
    }
    
    
    //THIS IS FOR POT[1]
    
    if (guess[0] == pot[0])
    {
        if (life<=0)
        {
            cout << "You have run out of lives.\n";
            cout << "It was a pleasure!\n";
            sleep(3);
            system("clear");
            
            //repeat?
            end();
        }
        
        sleep(1);
        cout << "\n\nAlright We're a third of the way there.\n";
        cout << "This is for the second number guess.\n";
        cout << "Please choose a number: \n";
        cin >> guess[1];
        
        if ((guess[1]>maxrand) || (guess<0))
        {
            cout << "\n\nYou need to choose a number between 0 and" << maxrand;
            sleep(2);
            cout << "\n\nQuit fooling around fool!!!\n";
            GetResults();
        }
        
        if (guess[1]==pot[1])
        {
            sleep(5);
            cout << "Great job! You are correct!\n\n";
            sleep(1);
            cout << pot[1] << " was the number I was looking for.\n";
            
        }
        
        else if (guess[1]>pot[1])
        {
            cout << "\nOh, you overshot it.\n";
            life--;
            sleep(1);
            cout << "You have " <<life << " lives remaining.\n\n";
            
            GetResults();
        }
        
        else if(guess[1]<pot[1])
        {
            cout << "\nOh, you went too small.\n";
            life--;
            sleep(1);
            cout << "You have " <<life <<" lives remaining.\n\n";
            GetResults();
        }
    }
    
    
    //THIS IS FOR POT[2]
    
    if (guess[1] == pot[1])
    {
        if (life<=0)
        {
            sleep(3);
            cout << "\nAww man! You were so close!\n";
            cout << "You have run out of lives.\n\n";
            cout << "It was a pleasure!";
            sleep(3);
            system("clear");
            
            //repeat?
            end();
        }
        
        cout <<"\nLast one!\n";
        cout << "Choose a number: \n";
        cin >> guess[1];
        
        if ((guess[2]>maxrand) || (guess<0))
        {
            cout << "\n\nYou need to choose a number between 0 and" << maxrand;
            sleep(2);
            cout << "\n\nQuit fooling around fool!!!";
            GetResults();
        }
        
        if (guess[2]==pot[2])
        {
            sleep(5);
            cout << "Great job! You are correct!\n\n";
            sleep(1);
            cout << pot[2] << " was the number I was looking for.\n";
            
            //repeat?
            end();
        }
        
        else if (guess[2]>pot[2])
        {
            cout << "\nOh, you overshot it.\n";
            life--;
            sleep(1);
            cout << "You have " <<life << " lives remaining.\n\n";
            
            GetResults();
        }
        
        else if(guess[2]<pot[2])
        {
            cout << "\nOh, you went too small.\n";
            life--;
            sleep(1);
            cout << "You have " <<life <<" lives remaining.\n\n";
            GetResults();
        }
    
    }
}







void end()
{
    
    cout << "Do you wish to continue?\n";
    cin >> answer;
    
   if ((answer == "no") || (answer == "No"))
   {
       cout << "Have a great day!";
   }
    
    
    
   else if ((answer == "yes") || (answer == "Yes"))
   {
        Start();
   }
        
}







//fun stuff
void easteregg()
{
    system("clear");
    cout << "W";
    sleep(1);
    cout << "3";
    sleep(1);
    cout << " ";
    sleep(1);
    cout << "4";
    sleep(1);
    cout << "r";
    sleep(1);
    cout << "3";
    sleep(1);
    cout << " ";
    sleep(1);
    cout << "L";
    sleep(1);
    cout << "3";
    sleep(1);
    cout << "g";
    sleep(1);
    cout << "1";
    sleep(1);
    cout << "0";
    sleep(1);
    cout << "n";
    sleep(1);
    cout << ".";
    sleep(3);
    system("clear");
    
    
}

//these are just empty lines! =D




