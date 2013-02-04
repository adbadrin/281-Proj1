#include "build.h"
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

//Tested, and works
void locationFrIndx(const& int index, const int dim[], int loc[]) {
	loc[2] = index / (dim[0] * dim[0]);
	loc[1] = ((index - loc[2] * loc[0] * loc[0]) / dim[0]) % dim[0];
	loc[0] = (index - loc[2] * loc[0] * loc[0]) % dim[0];
}

void indexFrLoc(int loc[], const int dim[], const int& index) {
	index = loc[2] * dim[0] * dim[0] + loc[1] * dim[0] + loc[0];
}



// NEED TO TEST AGAIN!
//dim is a two dimensional array, dim[0] = number of rows = number of columns, dim[1] = number of floors
bool buildFromMap(vector<square>& board, int dim[], int& startIndex) {
	string s; //Used for parsing through map with getline()
	square currSquare; //Used to store things before they are added into the map
	getline(cin, s);
	dim[0] = atoi(s.c_str()); //Number of rows/columns
	getline(cin, s);
	dim[1] = atoi(s.c_str()); //Number of floors
	board.resize(dim[0]*dim[0]*dim[1]);
	int counter = 0; //Makes sure there are an appropriate number of map lines
	while(getline(cin,s)) {
		if(s == "") {
			break;
		}
		else if((s[0] == '/') && (s[1] == '/')) {}
		else {
			if(s.length() != dim[0]) {
				return false;
			}
			for(int i = 0; i < s.length(); i++) {
				switch (s[i]) {
					case '.':
					case '#':
					case 'B':
						currSquare.type = s[i];
						break;
					case 'S':
						currSquare.type = s[i];
						startIndex = counter;
					default:
						if(isdigit(s[i])) {
							int j = s[i] - '0';
							if(j < 0) {
								return false;
							}
							else {
								currSquare.type = s[i];
							}
						}
						else {
							return false;
						}
						break;
				}
				currSquare.index = counter;
				board[counter] = currSquare;
				counter++;
			}
		}
	}
	if(counter != (dim[1] * dim[0] * dim[0])) {
	       return false;
	}	       
	return true;
}

void printMap (const vector<square> & board, int dim[]) {
	ostringstream ss;
	for(int i = 0; i < board.size(); i++) {
		if(i % dim[0] == 0) {
			ss << '\n';
		}
		ss << board[i].type;
	}
	cout<<ss.str()<< "\n";
}

bool buildFromList(vector<square>& board, int dim[], int& startIndex) {
	string s;
	string t;
	stringstream ss;
	square currSquare;
	int index;
	getline(cin, s);
	dim[0] = atoi(s.c_str()); //Figures out the number of rows/columns
	getline(cin, s);
	dim[1] = atoi(s.c_str()); //Figures out the number of floors
	board.resize(dim[0] * dim[0] * dim[1], currSquare); //Reshapes board to fit description AND fills it with normal squares
	int loc[3];
	string type;
	while(getline(cin, s)) {
		if(s == "") {
			break;
		}
		else if((s[0] == '/') && (s[1] == '/')) {}
		else { 
			s = s.substr(1, s.length() - 2);
			ss.str("");
			ss.clear();
			ss.str(s);
			for(int i = 0; i < 3; i++) {
				getline(ss, t, ',');
				loc[i] = atoi(t.c_str());
				if(loc[i] < 0) {
					return false;
				}
			}
			if((loc[0] >= dim[0]) || (loc[1] >= dim[0]) || (loc[1] >= dim[1])) {
				return false;
			}
			getline(ss,t,',');
			indexFrLoc(loc, dim, index);
			switch (t[0]) {
				case '#':
				case 'B':
				case '.':
					currSquare.type = t;
					break;
				case 'S':
					currSquare.type = t;
					startIndex = index; 
					break;
				default:
					if(isdigit(t[0])) {
						int j = t[0] - '0';
						if((j < 0) || (j > dim[1])) {
							return false;
						}
						currSquare.type = t;
					}
					else {
						return false;
					}
					break;
			}
			currSquare.index = index;
			board[index] = currSquare;
		}
	}
	for(int i = 0; i < board.size(); i++) {
		board[i].index = i;
	}
	return true;
}
