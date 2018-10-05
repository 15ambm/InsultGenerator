

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <exception>
#include <algorithm>

#include "insultgenerator_15ambm.h"

using namespace std;


const char* NumInsultsOutOfBounds::what() {
	return "invalid number of insults \n";
}

const char* FileException::what() {
	return "File cannot be read";
}


//TextFileException::TextFileException(const string& message) : message(message) {}

string InsultGenerator::talkToMe() {
	vector<string> out = generate(1);
	return out[0];
}

void InsultGenerator::initialize() {

	filein.open("test.txt");


	while (!filein.eof()) {
		string line;

		getline(filein, line, '	');
		first.push_back(line);

		getline(filein, line, '	');
		second.push_back(line);

		getline(filein, line, '\n');
		third.push_back(line);

	}

	filein.close();

}




vector<string> InsultGenerator::generate(int a) {

	string s = "";

	vector <string> output;

	if (a > 10000 || a < 0) {

		throw NumInsultsOutOfBounds();
	}

	srand(time(0));

	int r1, r2, r3;

	while (output.size() < a) {

		s = "Thou " + first[rand() % 50] + " " + second[rand() % 50]
			+ " " + third[rand() % 50] + "!";
		if (!searchVector(output, s))
			output.push_back(s);
	}

	sort(output.begin(), output.end());
	return output;

}

bool InsultGenerator::searchVector(vector<string> input, string s)
{
	unsigned int i;
	for (i = 0; i < input.size(); i++) {
		if (input.at(i) == s)
			return true;
	}
	return false;
}

void InsultGenerator::generateAndSave(string file, int n)
{

	fileout.open(file);
	vector<string> insults = generate(1000);
	sort(insults.begin(), insults.end());

	for (auto x : insults) {
		fileout << x << endl;
	}
}


