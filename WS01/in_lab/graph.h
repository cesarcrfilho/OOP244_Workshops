/*--------------------SENECA COLLEGE-----------------------------
Student     : Cesar Rodrigues
Student ID  : 127381168
Email       : cda-conceicao-rodrig@myseneca.ca
Date        : May 18 2017
Class       : OOP244SCC - Object Oriented Programming
Description : Workshop 01 - Graph Header
---------------------------------------------------------------*/

#ifndef SICT_GRAPH_H__
#define SICT_GRAPH_H__
#define MAX_NO_OF_SAMPLES 20 // Maximum number of samples in an graph

/*---------------------------------------------------------------
-------------------------PROTOTYPES------------------------------
---------------------------------------------------------------*/

namespace sict {

	// Prints a graph comparing the sample values visually
	void printGraph(int samples[], int noOfSamples);

	// Prints a scaled bar relevant to the maximum value in samples array
	void printBar(int val, int max);

	// Fills the samples array with the statistic samples
	void getSamples(int samples[], int noOfSamples);

	// Finds the largest sample in the samples array, if it is larger than 70,
	// therwise it will return 70.
	int findMax(int samples[], int noOfSamples);

}

#endif // !SICT_GRAPH_H__