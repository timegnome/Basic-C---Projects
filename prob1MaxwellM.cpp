//
//  main.cpp
//  Final
//
//  Created by MMaxwell on 12/10/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.
//

#include <iostream>

using namespace std;

double average(int*,int);

int main()
{
    int inValue=0, sizeofArr = 0, *contentScore, *skillScore;
    double averageContent = 0, averageSkill = 0;
    while(inValue >= 0)
    {
        cout << "Please enter the number of student evaluators" << endl;
        cin >> sizeofArr;
        contentScore = new int[sizeofArr];
        skillScore = new int[sizeofArr];
        cout << "Please enter the Id of the debator giving the presentation." << endl;
        cin >> inValue;
        if(inValue <= 0)
            return 0;
        cout << "Please enter the content scores ex 1 [enter]" << endl;
        for(int index = 0; index < sizeofArr; index++)
        {
            cin >> contentScore[index];
            cin.ignore();
        }
        cout << "Please enter the presentation skill scores" << endl;
        for(int index = 0; index < sizeofArr; index++)
        {
            cin >> skillScore[index];
            cin.ignore();
        }
        averageContent = average(contentScore, sizeofArr) * 0.6;
        averageSkill = average(skillScore, sizeofArr) * 0.4;
        cout << "Student "<< inValue <<": \nContent Average: " << averageContent <<endl;
        cout << "Presentation Average: "<< averageSkill << endl;
        cout << "Overall Rank: ";
        switch(int(averageContent + averageSkill))
        {
            case 1:
            case 2:
            {
                cout << "Poor(" << (averageContent + averageSkill) << ")" << endl;
                break;
            }
            case 3:
            {
                cout << "Mediocre(" << (averageContent + averageSkill) << ")" << endl;
                break;
            }
            case 4:
            case 5:
            {
                cout << "Superior(" << (averageContent + averageSkill) << ")" << endl;
            }
        }
    }
    return 0;
}

double average(int* score,int size)
{
    double average = 0;
    int highest = 0, lowest = score[0], index;
    bool inside = true;
    for(index = 0; index < size; index++)
    {
        if(score[index] > highest)
            highest = score[index];
        if(score[index] < lowest)
            lowest = score[index];
    }
    index = 0;
    do
    {
        if(highest == score[index])
        {
            score[index] = 0;
            inside = false;
        }
        index++;
    }while(inside);
    index = 0;
    do
    {
        if(lowest == score[index])
        {
            score[index] = 0;
            inside = false;
        }
        index++;
    }while(inside);
    
    for(index = 0; index < size; index++)
    {
        average += score[index];
    }
    if(size > 1)
        return average/(size-2);
    if(size == 2)
    {
        return average/2;
    }
    return average;
}

