// Original source attribution available
// Modified by M. Molodowitch
// Modified by Marcel Maxwell
// A Job class
// Note how comparison operators are defined.
#ifndef JOB_H
#define JOB_H

#include <iostream>
#include <string>

using namespace std;


class Job{
	friend ostream & operator<<( ostream &, const Job);


public:
    Job ( const int = -1,  const string = "", const int = -1, const string = "");  // constructor with default values
    ~Job();                       // destructor

    Job & setJobID( const int );
    Job & setJobDescription ( const string);
    Job & setPhoneExt( const int );
    Job & setContact(const string);
    int getJobID() const;
    const string getJobDescription() const;
    int getPhoneExt() const;
    string getContact() const;
   
  

    //Following three operator overloads are for use in Binary Search Tree
    // Comparisons betwen jobs are done by jobID only.

    bool operator<(const Job& right) const;
   
    bool operator>(const Job& right)const;
    
    bool operator==(const Job& right)const;

private:
    int jobID;
    string jobDescription;
    int phoneExt;
    string contact;

};

#endif



