// Assignment 4: Cuckoo Hashing algorithm
// Marcel Maxwell
// An open addressing method called Cuckoo Hashing
// INPUT: an input file containing strings of characters, one string per line
// OUTPUT: a detailed list of where the strings are inserted.    

#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
// cuckoo tables' size                                                        
const int tablesize = 19;
// combine the two 1-dimensional table into one 2-dimensional table           
char  t[tablesize][2][255];
// compute the hash functions
size_t f(char*, size_t);
// place a string in one of the hash tables
bool place_in_hash_tables(char*);
int main() {
	// the strings to be stored in the hash tables
	char s[255] = "";
	char null_st[] = "";
	size_t i, len;
	bool placed;
	// clear the tables
	for (i = 0; i< tablesize; i++) {
		strcpy(t[i][0], null_st);
		strcpy(t[i][1], null_st);
	}
	char filename[255] = "";
	// display the header
	cout << endl << "CPSC 335-x - Programming Assignment #4: ";
	cout << "Cuckoo Hashing algorithm" << endl;
	// read the strings from a file
	cout << "Input the file name (no spaces)!" << endl;
	cin >> filename;
	// open the file for reading
	FILE *file = fopen(filename, "r");
	if (file != NULL)
	{
		/* read line by line from the file */
		while (fgets(s, 255, file) != NULL) {
			// place null character at the end of the line instead of <return>
			len = strlen(s);
			s[len - 2] = '\0';
			// insert the string in the cuckoo table
			placed = place_in_hash_tables(s);
			// check whether the placement was successful
			if (!placed) {
				cout << "Placement has failed" << endl;
				return -1;
			}
		}
		fclose(file);
	}
	else
	{
		perror(filename); /* why didn't the file open? */
	}
	return 0;

}
bool place_in_hash_tables(char *s) {

	bool placed;
	size_t pos;
	int index;
	char temp_s[255], temp[255];
	strcpy(temp_s, s);
	// use a counter to detect loops
	int counter = 0;
	// start with table T1
	index = 0;
	placed = false;
	pos = f(temp_s, index);
	while ((!placed) && (counter < 2 * tablesize)) {
		if (strcmp(t[pos][index], "") == 0) {
			// the entry at index <pos> in the <index> hash table is available so store the string <temp_s> there
			cout << "String <" << temp_s << "> will be placed at";
			cout << " t[" << pos << "][" << index << "]" << endl;
			strcpy(t[pos][index], temp_s);
			placed = true;
			return placed;
		}
		else {
			// the entry at index <pos> in the <index> hash table is not available so 
			// obtain the string stored over there in variable <temp> and store the string <temp_s> there
			// now the string <temp> needs to be placed in the other table
			cout << "String <" << temp_s << "> will be placed at" << " t[" << pos;
			cout << "][" << index << "]" << " replacing <" << t[pos][index] << ">";
			cout << endl;
			// YOU NEED TO WRITE THE CODE TO STORE IN temp THE STRING STORED AT
			// t[pos][index] AND STORE IN t[pos][index] THE STRING temp_s
			strcpy(temp,t[pos][index]);
			strcpy(t[pos][index],temp_s);
			strcpy(temp_s, temp);
			// NOW temp_s CONTAINING THE EVICTED STRING NEEDS TO BE STORED 
			// IN THE OTHER TABLE
			// WRITE THE CODE TO SET index TO INDICATE THE OTHER TABLE
			// WRITE THE CODE TO CALCULATE IN pos THE HASH VALUE FOR temp_s
			index = !index;
			pos = f(temp_s, index);
			counter++;
		}
	}
	return placed;
};
// compute the hash functions
size_t f(char *s, size_t index) {
	// s is the string (the key) to which we apply the hash function
	// index indicates which hash function will be used
	// index == 0 means the first hash function
	// index == 1 means the second hash function
	size_t po, len;
	int i, val, temp;
	po = 1;
	len = strlen(s);
	if (index == 0) {
		val = s[0];
		val = val % tablesize;
		if (val < 0)
			val += tablesize;
		if (len == 1)
			return val;
		for (i = 1; i < len; i++)
		{
			temp = s[i];
			po *= 37;
			po = po % tablesize;
			if (po < 0)
				po += tablesize;
			val += temp * po;
			val = val % tablesize;
			if (val < 0) val
				+= tablesize;
		}
		return val;
	}
	else {
		// YOU NEED TO IMPLEMENT THE STEPS TO CALCULATE THE SECOND 
		// HASH FUNCTION
		val = s[len - 1];
		val = val % tablesize;
		if (val < 0)
			val += tablesize;
		if (len == 1)
			return val;
		for (i = 1; i < len; i++)
		{
			temp = s[len - i - 1];
			po *= 37;
			po = po % tablesize;
			if (po < 0)
				po += tablesize;
			val += temp * po;
			val = val % tablesize;
			if (val < 0) val
				+= tablesize;
			return val;
		}
	}
}
