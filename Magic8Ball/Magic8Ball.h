#ifndef MAGIC8BALL_H
#define MAGIC8BALL_H

// add all your includes 
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <algorithm>

using namespace std;

// global variables
vector<string> responseList;
const string RESPONSE_FILE_NAME = "Magic8BallResponses.txt";

// function prototypes
void displayTitle();
void playMagic8Ball();
void setMagic8Ball(string myFileName);
string askForString(string question);

#endif
