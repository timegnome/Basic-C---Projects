//
//  Fucntion.cpp
//  cs301
//
//  Created by MMaxwell on 9/15/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void read_temperatures_from_file(int*&,int*&,int&,string&);  // outputs a reportFile containing all the data parsed
void generate_report(int*,int*,int*&,int&,double&,double&,int&,int&);          // generates the report based on the file parsed
void print_report_to_file(int*,int,double,double,int,int,string);     // prints the report based on the file manipulated in the previous function

int main()
{
    int *highArr, *lowArr, *histoArr,locs,  High1, High2;
    double avergHigh, avergLow;
    string date;
	read_temperatures_from_file(highArr,lowArr,locs,date);
    generate_report(highArr,lowArr, histoArr,locs, avergHigh, avergLow, High1, High2);
    print_report_to_file(histoArr,locs,avergHigh,avergLow,High1,High2,date);
    return 0;
}
void read_temperatures_from_file(int* &highTemp, int* &lowTemp, int& locations, string& date)
{
    ifstream inFile;
	inFile.open("/Users/local/ACAD/mmaxwell/Desktop/cs301/cs301/day5/day5/temperature_test.txt");
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
        //int temp1,temp2;
        inFile>>highTemp[count];
        inFile>>lowTemp[count];
        /*if(temp1>temp2)
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
    inFile.close();
}
void generate_report(int* highArr, int* lowArr, int* &histoArr, int& locs, double& avergHigh, double& avergLow, int& High1, int& High2)
{
    int average=0;
    for(int index=0; index<locs; index++)
    {
        average+=highArr[index];
    }
    avergHigh = average/locs;
    for(int index=0; index<locs; index++)
    {
        average+=lowArr[index];
    }
    avergLow=average/locs;
    High1=highArr[0];
    High2=lowArr[0];
    for(int count=0; count<locs; count++)
    {
        if(High1<highArr[count])
        {
            High1=highArr[count];
        }
        if(High2>lowArr[count])
        {
            High2=lowArr[count];
        }
    }
    histoArr=new int[12];
    for(int x=0; x<12;x++)
    {
        histoArr[x]=0;
    }
    for(int index=0;index<locs;index++)
    {
        if(highArr[index]<0)
            histoArr[0]++;
        else if (highArr[index]>99)
        {
            histoArr[11]++;
        }
        else
        {
            histoArr[highArr[index]/10+1]++;
        }
    }
}

void print_report_to_file(int* histo, int locations, double avgHigh, double avgLow, int High1, int High2, string date)
{
	ofstream outFile;
	outFile.open("report1.txt");
    outFile<<"The Date is "<<date<<endl;
    outFile<<"The number of locations are "<<locations<<endl;
    outFile<<"The average for the high of temperatures is: ";
    outFile<<avgHigh<<endl;
    outFile<<"The average for the low of temperatures is: ";
    outFile<<avgLow<<endl;
    outFile<<"The highest temperature in all the locations is "<<High1<<endl;
    outFile<<"The lowest temperature in all the locations is "<<High2<<endl;
    outFile<<"The histogram graph for the amount of high temperatures in the locations are as follows:"<<endl;
    for(int count=0; count<11; count++)
    {
        cout<<histo[count]<<" ";
        if(count==0)
            outFile<<"<0|";
        else
            outFile<<"<="<<count*10-1<<"|";
        for(int print=0; print<histo[count];print++)
        {
            outFile<<"*";
        }
        
        outFile<<endl;
    }
    outFile<<"99<|";
    for(int print=0; print<histo[11];print++)
    {
        outFile<<"*";
    }
    outFile.close();
}
