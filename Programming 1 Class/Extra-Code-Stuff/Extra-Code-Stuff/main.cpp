//
//  main.cpp
//  Extra-Code-Stuff
//
//  Created by Alan Trevino De Arcos on 10/7/14.
//  Copyright (c) 2014 Alan Trevino. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    
    
    cout << "Hello, World!\n";
    cout << "Pick a number:\n";
    int choice;
    cin >> choice;
    
    if (choice > 50)
    {
        cout << "This number is greater than 50\n";
    }
    
    else if (choice < 50)
    {
        cout << "This number is smaller than 50\n\n";
    }
    
    
    return 0;
}
