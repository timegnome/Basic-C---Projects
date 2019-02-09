//
//  mainFunc.cpp
//  cs301
//
//  Created by MMaxwell on 10/1/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstring>
//Make sure to include user defined header files
#include "Date.h"
#include "Beverage.h"

using namespace std;

//Function Prototypes

void printMenu();

int main()

{
    /*variables ----------------------------------------------------*/
    Date today(2,25,2015); // constructor sets today's date (month, day, year)
    Beverage drinkRecord[200]; // Array to store drink information
    int count = 0;// ALWAYS needed when working with arrays to store number of used locations
    // Temp variables used to store file & user input prior to storing in object
    char charValue; // used for junk & user selected value
    char tempDrinkName[25];
    int tempCaffeineAmount;
    double tempPrice;
    int tempMonth, tempDay, TempYear;
    Date tempDate;
    int totalCaffeine=0; // used to store total caffeine when printing table
    double totalPrice=0.0; // used to store total price when printing table
    ifstream inFile; // used to read in data from MyCoffeeRecord.txt
    /*Begin Processing --------------------------------------------*/
    // Step 1. Read in coffee record from file
    inFile.open("/Users/local/ACAD/mmaxwell/Downloads/MyCoffeeRecord (1).txt"); // attaching file to variable
    
    if(!inFile)// check that file is attached
    {
        cout << "File not attached." <<endl;
        return 1; // exits program
    }
    while(inFile>>tempCaffeineAmount)// grabs caffeiene int here. Stops when no value left to grab
    {
        
        // read in the rest of values for the single row
        
        inFile>>tempPrice>>tempMonth>>charValue>>tempDay>>charValue>>TempYear;
        inFile.ignore(); // ignores unnecessary whitespace character
        inFile.getline(tempDrinkName,25,'\n');
        
        // Used the line below to check that correct values were read from file
        // cout << tempCaffeineAmount << " " <<tempPrice<< " "<<tempMonth<<charValue<<tempDay<<charValue<<TempYear<< " " <<tempDrinkName<< "***"<<endl;
        // Step 2. Save user input into my classes
        //Save Date
        
        tempDate.setDate(tempMonth,tempDay,TempYear);
        // Save values in Beverage Class object of my array
        
        drinkRecord[count].setDrinkName(tempDrinkName).setcaffeineAmount(tempCaffeineAmount).setPrice(tempPrice).setDatePurchased(tempDate);
        
        // Used the line below to check that correct values were saved
        // drinkRecord[count].print();
        count++; // Incremented count to move to next location in my object array
    }
    inFile.close(); // CLOSE THE FILE!
    
    // Step 3. Start the main loop for the program
    
    cout << "~*~*~*~* Welcome to My Coffee & Caffeine Tracker Program *~*~*~*~"<<endl; //    welcome message
    printMenu();
    cin>>charValue;// get value from user
    charValue = toupper(charValue); // convert answer to uppercase
    while(charValue != 'Q' ) // begin while loop
    {
        switch(charValue)
        {
            case 'A':{
                // Save values in Beverage Class object of my array in 1 line
                //Reads the data from the user to temp values before being saved to the array
                cout<<"Please enter the drink info please: "<<endl<<"Caffiene Amount: ";
                cin>>tempCaffeineAmount;
                cout<<"Price: ";
                cin>>tempPrice;
                cout<<"MM/DD/YYYY : ";
                cin>>tempMonth>>charValue>>tempDay>>charValue>>TempYear;
                cout<<"Drink: ";
                cin.ignore();
                cin.getline(tempDrinkName,25);
                tempDate.setDate(tempMonth,tempDay,TempYear);
                // Save values in Beverage Class object of my array
                if(count>=200)
                {
                    cout<<"To many drinks in the array"<<endl;
                    break;
                }
                drinkRecord[count].setDrinkName(tempDrinkName).setcaffeineAmount(tempCaffeineAmount).setPrice(tempPrice).setDatePurchased(tempDate);
                count++;// Incremented count to move to next location in my object array
                cout << "Drink added to record!" <<endl<<endl;
                break;}
    
            case 'P':{
                // print - usually this should be a function
                cout << endl << "-------------------------------------------------"<<endl;
                // set totals to 0
                totalCaffeine=0; // used to store total caffeine when printing table
                totalPrice=0.0; // used to store total caffeine when printing table
                for(int i = 0; i < count; i++)
                {
                    drinkRecord[i].print();
                    //Add statistics
                    totalCaffeine+=drinkRecord[i].getcaffeineAmount();
                    totalPrice+=drinkRecord[i].getPrice();
                }
                //output statistics
                cout << "Total Cups: "<<count<< "\tTotal Caffeine: "<<totalCaffeine<<"\tTotal Cost: $"<<totalPrice<<endl<<endl;
                break;}

            case 'Q':{
                // Should never get to this case
                cout << "Goodbye!" <<endl<<endl;
                break;}
                
            default:{
                cout << "Error! Unknown value. Please try again." <<endl<<endl;
                break;}
                
        }//end switch
        //Need to update while loop condition
        cout << "Please select another option.\n>>";
        cin>>charValue;// get value from user
        charValue = toupper(charValue); // convert answer to uppercase
    }//end while
    // Step 4. Print Values to File in correct data order
    //Print Values to MyCoffeeRecord.txt
    ofstream outFile;
    outFile.open("/Users/local/ACAD/mmaxwell/Downloads/MyCoffeeRecord (1).txt");
    for(int i = 0; i < count; i++)// for every populaed object in the array
    {
        drinkRecord[i].print(outFile); // print out a single object to the file
    }
    outFile.close(); // CLOSE THE FILE
    cout <<endl<< "Goodbye!" << endl; // closing message
    return 0; // Always return
    
}

//Function Definitions
void printMenu()
{
    cout << "Please select one of the following:" <<endl;
    cout << "A: Add a Coffee Drink" <<endl;
    cout << "P: Print Table & Stats to Screen" <<endl;
    cout << "Q: Quit the Program" <<endl;
    cout << ">> ";
}

