// Assignment 1: Alternating disks problem, left-to-right algorithm
// MArcel Maxwell
// Given 2n alternating disks disks (light-dark), starting with light
// the program reads the number of single color disks (light or dark),
// arranges the disks in the correct order and outputs the number of swaps
// INPUT: an even positive integer n and a list of 2n disks of alternating 
// colors light-dark, starting with light
// OUTPUT: a list of 2n disks, the first n disks are dark and the next n 
// disks are light, and an integer m representing the number of moves necessary
// to move the dark ones before the light ones

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream output;
	output.open("Results_1.txt",ios_base::trunc);
	int sortedblacks = 0, NumbOfSwaps = 0, n = 0;
	// display the header
	output << endl << "CPSC 335-1 - Programming Assignment #1" << endl;
	output << "The alternating disks problem: left-to-right algorithm" << endl;
	output << "Enter an even number of single color disks (light or dark)" << endl;
	// read the number of disks
	cin >> n; 
	char *disklist;
	disklist = new char[2*n];
	for (int i = 0; i < n; i++)
	{
		disklist[2 * i] = 'w';
		disklist[2 * i + 1] = 'b';
	}
	output << "List before sorting:\n";
	for (int i = 0; i < 2 * n; i++)
	{
		output << disklist[i];
	}
	output << endl;
	for (int k = 0; k < n; k++)
	for (int i = 0; i < 2*n;)
	{
		if (disklist[i] == 'b')
		{
			i++;
		}
		else
		{
			int j = i;
			while (i<2*n)
			{
				if (disklist[i] == 'b')
				{
					char temp = disklist[j];
					disklist[j] = disklist[i];
					disklist[i] = temp;
					NumbOfSwaps++;
					i++;
					break;
				}
				else
				{
					i++;
				}
			}
		}
	}
	output << "List after sorting:\n";
	for (int i = 0; i < 2 * n; i++)
	{
		output << disklist[i];
	}
	output << "\n Number of swaps:" << NumbOfSwaps << endl;
	delete[] disklist;
	return EXIT_SUCCESS;
}