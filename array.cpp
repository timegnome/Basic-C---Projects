//
//  main.cpp
//  cs301
//
//  Created by MMaxwell on 9/15/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
	ifstream inFile;
	ofstream outFile;
	inFile.open("/Users/local/ACAD/mmaxwell/Downloads/temperature_test.txt");
	outFile.open("report.txt");
	int *highTemp, *lowTemp, locations=1,tempHigh,tempLow,histogram[12];
    double average=0;
    string date;
    getline(inFile,date);
    inFile>>locations;
    if(locations<2)
    {
        highTemp=new int[2];
        lowTemp= new int[2];
    }
    else if(locations>100)
    {
        highTemp=new int[100];
        lowTemp= new int[100];
    }
    else
    {
        highTemp=new int[locations];
        lowTemp= new int[locations];
    }
    for(int count=0; count<locations; count++)
    {
      //  int temp1,temp2;
        inFile>>highTemp[count];
        inFile>>lowTemp[count];
/*        if(temp1>temp2)
        {
            highTemp[count]=temp1;
            lowTemp[count]=temp2;
        }
        else
        {
            lowTemp[count]=temp1;
            highTemp[count]=temp2;
        }*/
    }
    outFile<<"The Date is "<<date<<endl;
    outFile<<"The number of locations are "<<locations<<endl;
    outFile<<"The average for the high of temperatures is: ";
    for(int index=0; index<locations; index++)
    {
        average+=highTemp[index];
    }
    outFile<<average/locations<<endl;
    average=0;
    for(int index=0; index<locations; index++)
    {
        average+=lowTemp[index];
    }
    outFile<<"The average for the low of temperatures is: ";
    outFile<<average/locations<<endl;
    tempHigh=highTemp[0];
    tempLow=lowTemp[0];
    for(int count=0; count<locations; count++)
    {
        if(tempHigh<highTemp[count])
        {
            tempHigh=highTemp[count];
        }
        if(tempLow>lowTemp[count])
        {
            tempLow=lowTemp[count];
        }
    }
    outFile<<"The highest temperature in all the locations is "<<tempHigh<<endl;
    outFile<<"The lowest temperature in all the locations is "<<tempLow<<endl;
    outFile<<"The histogram graph for the amount of high temperatures in the locations are as follows:"<<endl;
    for(int x=0; x<12;x++)
    {
        histogram[x]=0;
    }
    for(int index=0;index<locations;index++)
    {
        if(highTemp[index]<0)
            histogram[0]++;
        else if (highTemp[index]>99)
        {
            histogram[11]++;
        }
        else
        {
            histogram[highTemp[index]/10+1]++;
        }
    }
    for(int count=0; count<11; count++)
    {
        if(count==0)
           outFile<<"<=0|";
        else
        outFile<<"<="<<count*10-1<<"|";
        for(int print=0; print<histogram[count];print++)
        {
            outFile<<"*";
        }
        
        outFile<<endl;
    }
    outFile<<"99<|";
    for(int print=0; print<histogram[11];print++)
    {
        outFile<<"*";
    }
    inFile.close();
    outFile.close();
    return 0;
}


