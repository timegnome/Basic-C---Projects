// Assignment 3: Euclidean traveling salesperson problem: improved nearest neighbor algorithm
// Marcel Maxwell
// A special case of the classical traveling salesman problem (TSP) where the input is a Euclidean graph
// INPUT: a positive integer n and a list P of n distinct points representing vertices of a Euclidean graph
// OUTPUT: a list of n points from P representing a Hamiltonian cycle of relatively minimum total weight 
// for the graph.


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <chrono>
using namespace std;


struct point2D {
	float x; // x coordinate
	float y; // y coordinate
};


void print_cycle(int, point2D*, int*);
// function to print a cyclic sequence of 2D points in 2D plane, given the 
// number of elements and the actual sequence stored as an array of 2D points
// SAME AS IN THE PREVIOUS PROGRAM


int farthest_point(int, point2D*);
// function to return the index of a point that is furthest apart from some other point


int nearest(int, point2D*, int, bool*);
// function to calculate the nearest unvisited neighboring point


int main() {

	point2D *P;
	int *M;
	bool *Visited;
	int i, n;
	float dist;
	int A, B;

	// display the header
	cout << endl << "CPSC 335-1 - Programming Assignment #3" << endl;
	cout << "Euclidean traveling salesperson problem: improved nearest neighbor algorithm" << endl;
	cout << "Enter the number of vertices (>2) " << endl;

	// read the number of elements
	cin >> n;

	// if less than 3 vertices then terminate the program
	if (n <3)
		return 0;

	// allocate space for the sequence of 2D points
	P = new point2D[n];

	// read the sequence of distinct points
	cout << "Enter the points; make sure that they are distinct" << endl;
	for (i = 0; i < n; i++) {
		cout << "x=";
		cin >> P[i].x;
		cout << "y=";
		cin >> P[i].y;
	}

	// allocate space for the INNA set of indices of the points
	M = new int[n];
	// set the best set to be the list of indices, starting at 0
	for (i = 0; i<n; i++)
		M[i] = i;

	// Start the chronograph to time the execution of the algorithm
	auto start = chrono::high_resolution_clock::now();

	// allocate space for the Visited array of Boolean values
	Visited = new bool[n];
	// set it all to False
	for (i = 0; i<n; i++)
		Visited[i] = false;

	// calculate the starting vertex A
	A = farthest_point(n, P);
	// add it to the path
	i = 0;
	M[i] = A;

	// set it as visited
	Visited[A] = true;

	for (i = 1; i<n; i++) {
		// calculate the nearest unvisited neighbor from node A
		B = nearest(n, P, A, Visited);
		// node B becomes the new node A
		A = B;
		// add it to the path
		M[i] = A;
		Visited[A] = true;
	}

	// calculate the length of the Hamiltonian cycle
	dist = 0;
	for (i = 0; i < n - 1; i++)
		dist += sqrt((P[M[i]].x - P[M[i + 1]].x)*(P[M[i]].x - P[M[i + 1]].x) +
		(P[M[i]].y - P[M[i + 1]].y)*(P[M[i]].y - P[M[i + 1]].y));
	dist += sqrt((P[M[0]].x - P[M[n - 1]].x)*(P[M[0]].x - P[M[n - 1]].x) +
		(P[M[0]].y - P[M[n - 1]].y)*(P[M[0]].y - P[M[n - 1]].y));

	// End the chronograph to time the loop
	auto end = chrono::high_resolution_clock::now();

	// after shuffling them
	cout << "The Hamiltonian cycle of a relative minimum length " << endl;
	print_cycle(n, P, M);
	cout << "The relative minimum length is " << dist << endl;

	// print the elapsed time in seconds and fractions of seconds
	int microseconds =
		chrono::duration_cast<chrono::microseconds>(end - start).count();
	double seconds = microseconds / 1E6;
	cout << "elapsed time: " << seconds << " seconds" << endl;

	// de-allocate the dynamic memory space
	delete[] P;
	delete[] M;
	return EXIT_SUCCESS;
}


int farthest_point(int n, point2D *P)
// function to calculate the furthest distance between any two 2D points
{
	// YOU NEED TO IMPLEMENT THIS FUNCTION
	float dist = 0;
	float max_dist = 0;
	int farthest = 0;
	for (int j = 0; j < n; j++) {
		dist = (P[1].x - P[j].x)*(P[1].x - P[j].x) + (P[1].y - P[j].y)*(P[1].y - P[j].y);
		if (max_dist < dist)
		{
			max_dist = dist;
			farthest = j;
		}
	}
	return farthest;
}


int nearest(int n, point2D *P, int A, bool *Visited)
// function to calculate the nearest unvisited neighboring point
{
	// YOU NEED TO IMPLEMENT THIS FUNCTION
	float dist = 0;
	float min_dist = 0;
	int nearest = 0;
	for (int j = 0; j < n; j++) {
		if(!Visited[j])
		{
			dist = (P[A].x - P[j].x)*(P[A].x - P[j].x) + (P[A].y - P[j].y)*(P[A].y - P[j].y);
			if (min_dist > dist)
			{
				min_dist = dist;
				nearest = j;
			}
		}
	}
		return nearest;
}


void print_cycle(int n, point2D *P, int *seq)
// function to print a sequence of 2D points in 2D plane, given the number of elements and the actual 
// sequence stored as an array of 2D points
// n is the number of points
// seq is a permutation over the set of indices
// P is the array of coordinates
{
	// YOU NEED TO IMPLEMENT THIS FUNCTION
	for (int i = 0; i < n; i++)
	{
		cout << "(" << P[seq[i]].x << "," << P[seq[i]].y << "),";
	}
	cout << endl;
}
