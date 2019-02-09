//
//  main.cpp
//  tex v binary
//
// The difference between a text file and a binary file is that if the data is stored or extracted properly from a binary
// file it can be used more efficiently. Binary file is binary data file text contains strings that could be only read
// through text.
//
//
//  Created by MMaxwell on 9/10/15.
//  Copyright (c) 2015 MMaxwell. All rights reserved.


#include <iostream>
#include <fstream>

using namespace std;

class Student_Record
{
public:
    Student_Record(int ID,double points)
    {
        CWID=ID;
        total_points_earned=points;
    }
    Student_Record(){CWID=0,total_points_earned=0;};
    int CWID;
    double total_points_earned;
    
};

int main(int argc, const char * argv[])
{

    ifstream inFile;
    ofstream outFile;
    int numArr[2],numRead[2];
    Student_Record *Stud_Arr,Stud1;
    numArr[0]=1;
    numArr[1]=2;
    outFile.open("text_file1.txt");
    outFile <<numArr[0]<<endl;
    outFile <<numArr[1]<<endl;
    outFile.close();
    
    outFile.open("bin_file1.bin");
    outFile.write(reinterpret_cast< char*>(&numArr),sizeof(int));
    outFile.close();
    
    inFile.open("text_file1.txt");
    inFile>>numRead[0];
    inFile>>numRead[1];
    inFile.close();
    cout<<"First number in "<<numRead[0]<<" , Second number"<< numRead[1]<<endl;
    
    inFile.open("bin_file1.bin");
    inFile.read(reinterpret_cast< char*>(&numRead),sizeof(int));
    inFile.close();
    cout<<"First number in "<<numRead[0]<<" , Second number"<< numRead[1]<<endl;
    
    outFile.open("bin_file1.bin");
    Stud_Arr = new Student_Record[4];
    Stud_Arr[0].CWID=123;
    Stud_Arr[1].CWID=321;
    outFile.write(reinterpret_cast<const char*>(&Stud_Arr[0]),sizeof(Student_Record));
    outFile.write(reinterpret_cast<const char*>(&Stud_Arr[1]),sizeof(Student_Record));
    outFile.close();
    
    outFile.open("text_file2.txt");
    outFile<<Stud_Arr[0].CWID<<endl;
    outFile<<Stud_Arr[0].total_points_earned<<endl;
    outFile<<Stud_Arr[1].CWID<<endl;
    outFile<<Stud_Arr[1].total_points_earned<<endl;
    outFile.close();
    
    inFile.open("text_file2.txt");
    inFile>>Stud_Arr[2].CWID;
    inFile>>Stud_Arr[2].total_points_earned;
    inFile>>Stud_Arr[3].CWID;
    inFile>>Stud_Arr[3].total_points_earned;
    inFile.close();
    cout<<"First CWID in "<<Stud_Arr[2].CWID<<" , Second number"<< Stud_Arr[2].total_points_earned<<endl;
    cout<<"First CWID in "<<Stud_Arr[3].CWID<<" , Second number"<< Stud_Arr[3].total_points_earned<<endl;
    
    inFile.open("bin_file1.bin");
    inFile.read(reinterpret_cast<char*>(&Stud_Arr[2]),sizeof(Student_Record));
    inFile.read(reinterpret_cast<char*>(&Stud_Arr[3]),sizeof(Student_Record));
    delete [] Stud_Arr;
    inFile.close();
    cout<<"First CWID in "<<Stud_Arr[2].CWID<<" , Second number"<< Stud_Arr[2].total_points_earned<<endl;
    cout<<"First CWID in "<<Stud_Arr[3].CWID<<" , Second number"<< Stud_Arr[3].total_points_earned<<endl;
    Stud_Arr=new Student_Record[5];
    for(int reset=0;reset<5;reset++)
    {
        Stud_Arr[reset].CWID=reset*7;
    }
    outFile.open("file1.bin");
    for(int count=0; count<5;count++)
    {
        outFile.write(reinterpret_cast<const char*>(&Stud_Arr[count]),sizeof(Student_Record));
    }
    delete [] Stud_Arr;
    outFile.close();
    
    inFile.open("file1.bin");
    Stud_Arr=new Student_Record[5];
    for(int count=0; count<5;count++)
    {
        inFile.read(reinterpret_cast<char*>(&Stud_Arr[count]),sizeof(Student_Record));
    }
    inFile.seekg(0);
    inFile.seekg(2*sizeof(Stud_Arr));
    
    inFile.read(reinterpret_cast<char*>(&Stud1),sizeof(Student_Record));
    cout<<Stud1.CWID<<endl;
    inFile.close();
    return 0;
}

