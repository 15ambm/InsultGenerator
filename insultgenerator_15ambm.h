#pragma once
/*
 * insultgenerator15ambm.h
 *
 *  Created on: Sep 26, 2018
 *      Author: Alex Mason / 15ambm
 */

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

class InsultGenerator { //Insult Generator class, contains five functions
private:
	vector <string> first; // Three string vectors which will be filled with the words in each column of the source file
	vector <string> second;// Second column of words
	vector <string> third;// Third column of words

	ifstream filein;	//file stream for reading the source file of insult words
	ofstream fileout; //file stream for writing insults to a file 

public:

	string talkToMe(); //returns a single generated instult 

	void initialize(); //reads the source file and parses text. Places the words in each column into the first, second and third vectors respectively 

	vector<string> generate(int a); //Using pseudo random number generation words are chosen from each of the three vectors and comnbined 
									// into complete insults. It is then verified if they are unique and if so they are added to an output vector
									// containing the specified number of insults up to 10 000

	bool searchVector(vector<string> input, string s); //searches the passed vector and compares to passed string. If the string doesn't exist in
														// in the vector is returns true, otherwise false

	void generateAndSave(string file, int n); //generates specified number of insults and sorts them alphabetically. The sorted vector is then
											// saved to the specified output file 
};


class NumInsultsOutOfBounds : public exception { //If the number of insults requested is invalid throw a NumInsultsOutOfBounds exception 
	int num; //number of insults 
public:
	const char* what(); //returns the error message
};

class FileException : public exception { //If the file is not valid throw a FileException
	
public:
	const char* what(); //returns the error message 
};