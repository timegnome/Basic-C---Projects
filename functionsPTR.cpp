//
//  functionsPTR.cpp
//  cpcs301
//
//  Created by MMaxwell on 9/24/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void sort(int, int[], float[], string[], bool(*compare)(int,int));
bool compareFunction1(int,int);
bool compareFunction2(int,int);
double saleForDay(int[], float[], int);
void printToFile(int, int [], float [], string [],string);

int main()
{
    ifstream inFile;
    string date, *list;
    int length=0, *amount_sold;
    char junk;
    float *price;
    bool (*functionPtr)(int,int);
    functionPtr=compareFunction2;
    inFile.open("/Users/local/ACAD/mmaxwell/Downloads/Sales_Test.txt");
    while(getline(inFile,date))
    {
        length++;
    }
    inFile.close();
    if(length>0)
    {
        length-=1;
        inFile.open("/Users/local/ACAD/mmaxwell/Downloads/Sales_Test.txt");
        amount_sold=new int[length];
        price=new float[length];
        list=new string [length];
        getline(inFile, date);
        for(int count=0;count<length;count++)
        {
            inFile>> amount_sold[count];
            inFile>> junk;
            inFile>> price[count];
            getline(inFile, list[count]);
            //cout<<amount_sold[count]<<junk<<price[count]<<list[count]<<endl;
        }
        inFile.close();
        sort(length,amount_sold,price,list,functionPtr);
        printToFile(length, amount_sold, price, list, date);
    }
    return 0;
}
void sort (int listLength, int amount_sold[], float price[], string item_name[], bool (*compare)(int,int))
{
    int tempSold;
    float tempPrice;
    string tempItem;
    for (int count=0; count<listLength;count++)
    {
        for(int index=count; index<listLength; index++)
        {
            if(compare(amount_sold[count],amount_sold[index]))
            {
                tempSold= amount_sold[count];
                tempPrice= price[count];
                tempItem=item_name[count];
                amount_sold[count]=amount_sold[index];
                amount_sold[index]=tempSold;
                price[count]=price[index];
                price[index]=tempPrice;
                item_name[count]=item_name[index];
                item_name[index]=tempItem;
            }
        }
    }
}
void printToFile(int listLength, int amount_sold[], float price[], string item_names[], string date)
{
    ofstream outFile;
    int mostItems, leastItems,index=0;
    bool (*functionPtr1)(int,int);
    outFile.open("report3.txt");
    outFile<<"Sales on "<<date<<endl;
    outFile<<"Total sales: "<<saleForDay(amount_sold, price, listLength-1)<<endl;
    mostItems=amount_sold[0];
    leastItems=amount_sold[listLength-1];
    outFile<<"Most sold: ";
    while(amount_sold[index]==mostItems)
    {
        outFile<<item_names[index]<<endl;
        index++;
    }
    outFile<<"Least sold: ";
    index=listLength-1;
    while(amount_sold[index]==leastItems)
    {
        outFile<<item_names[index]<<endl;
        index-=1;
    }
    mostItems=0;
    for(int count=0; count<listLength; count++)
    {
        if(amount_sold[mostItems]*price[mostItems]<amount_sold[count]*price[count])
        {
            mostItems=count;
        }
    }
    outFile<<"Item with most income: "<<item_names[mostItems]<<endl;
    functionPtr1=compareFunction1;
    sort(listLength,amount_sold,price,item_names,functionPtr1);
    outFile<<"Least popular to Most popular:"<<endl;
    for(int count=0;count<listLength;count++)
    {
        outFile<<count<<". "<< item_names[count]<<"("<< amount_sold[count]<<")"<<endl;
    }
    
}
bool compareFunction1(int first,int second)
{
    return first>second;
}
bool compareFunction2(int first,int second)
{
    return first<second;
}
double saleForDay(int amount[], float price[], int endOfList)
{
    if(endOfList<0)
        return 0;
    else
    return saleForDay(amount,price,endOfList-1) + (double)(amount[endOfList]*price[endOfList]);
}