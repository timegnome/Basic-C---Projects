// Revised by M. Molodowitch 1/10/06
// 
// Member function definitions for class Job
#include <iostream>
#include <string>
#include <cassert>
#include "Job.h"

using namespace std;



Job::Job(const int ID, const string description, const int phoneExt, const string contactN)
{
   setJobID ( ID );

   setJobDescription  (description);

   setPhoneExt ( phoneExt);
    
    setContact ( contactN);
}


// Destructor can be overloaded to deallocate
// any dynamically allocated memory.
// No dynamically allocated memory here, so nothing in body
Job::~Job()
{

}


Job & Job::setJobDescription ( const string description)
{
	jobDescription = description;

	return *(this);
}



Job & Job::setJobID( const int jobNumber ){

	jobID = jobNumber;
	
	return (*this);
	
}


Job & Job::setPhoneExt( const int phoneNumber )
{
	phoneExt = phoneNumber;
	
	return (*this);
	
}
Job & Job::setContact(const string contactName)
{
    contact = contactName;
    
    return (*this);
}


const string Job::getJobDescription() const
{
	return jobDescription;
}


int Job::getJobID() const
{
	return jobID;
}


int Job::getPhoneExt() const
{
	return phoneExt;
}

string Job::getContact() const
{
    return contact;
}
// The print function can be modidfied to suit your need.
ostream & operator<<( ostream & outstream, const Job job)
{
	outstream << "\nJob:  " << job.getJobID()<< "\nJob Description:  " << job.getJobDescription()
			<< "\nPhone Extension: " << job.getPhoneExt()<<"\nContact: "<<job.getContact();

	return outstream;
}


//Following for use in Binary Search Tree

   // for comparison operators <, >, ==,  only the jobID value is looked at.
   //
   // This means that one job object will equal another if the job ID's are the same,
   // even if the other fields differ.
   //
   // When looking for an old job with a particular ID, you can create a new job object
   // with the same ID but with default values for the other fields.  If an old job is equal,
   // to your new job (i.e. same job ID), you have found what you were looking for.  


   bool Job::operator<(const Job& right) const 
   {
	   return (jobID < right.jobID);
   }
   
   bool Job::operator>(const Job& right)const 
   {
	   return (jobID > right.jobID);
   }

   
   // This definition of equality means if job1 has jobID == 5, jobDescription == "", contactName == "",
   // and phoneExt == -1, and job2 has jobID == 5, jobDescription == "Paint CS building outside railings",
   
   // contactName == "James Whoever", and phoneExt == 5555,
   // job1 == job2
   
   bool Job::operator==(const Job& right)const 
   {
	   return (jobID == right.jobID);
   }
