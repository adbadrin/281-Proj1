#include <iostream>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include "print.h"
#include "stqu.h"
using namespace std;

string relToPrev(int currIndex, int prevIndex, const int dim[]) {
	int currLoc[3];
	int prevLoc[3];
	locationFrIndx(currIndex, dim, currLoc);
	locationFrIndx(prevIndex, dim, prevLoc);
	if(abs(prevLoc[0] - currLoc[0]) == 1) {
		if(prevLoc[0] - currLoc[0] == 1) {
			return "n";
		}
		else {
			return "s";
		}
	}
	if(abs(prevLoc[1] - currLoc[1]) == 1) {
		if(prevLoc[1] - currLoc[1] == 1) {
			return "w";
		}
		else {
			return "e";
		}
	}
	return "p";
}


	
void putPathOnBoard(vector<square>& board, const int dim[], const int& endIndex) {
	int currIndex = endIndex;
	int prevIndex;
	string prevDir;
	while(true) {
		if(board[currIndex].cameFrom == -1) {
			break;
		}
		prevIndex = board[currIndex].cameFrom;
		prevDir = relToPrev(currIndex, prevIndex, dim);
		board[prevIndex].type = prevDir;
		currIndex = prevIndex;
	}
}

//THIS WORKS NOW!!!
void printMapSln(vector<square>& board, const int dim[], int endIndex, bool putPath) {
	ostringstream ss;
	ss << dim[0] << "\n";
	ss << dim[1] << "\n";
	int floor = dim[1] - 1;
	if(putPath) {
		putPathOnBoard(board, dim, endIndex);
	}
	int i;
	ss << "//room " << floor << "\n";
	for(i = 0; i < board.size(); i++) {
		if((i!=0) && (i % dim[0] == 0)) {
			ss << '\n';
		}
		if((i!=0) && (i % (dim[0] * dim[0]) == 0)) {
				floor--;
				ss << "//room " << floor << "\n";
		}
		ss << board[i].type;
	}
	cout << ss.str() << "\n";
}

void putPathOnBoard2(vector<square>& board, const int dim[], const int& endIndex, int& startIndex) {
	int currIndex = endIndex;
	int prevIndex = board[prevIndex].cameFrom;
	int temp;
	string prevDir;
	while(true) {
		if(board[prevIndex].cameFrom == -1) {
			break;
		}
		temp = board[prevIndex].cameFrom;
		prevDir = reltoPrev(currIndex, prevIndex, dim);
		board[prevIndex].type = prevDir;
		board[prevIndex].cameFrom = currIndex;
		currIndex = prevIndex;
		prevIndex = temp;
	}
	startIndex = temp;
}

void printListSln(vector<square>& board, const int dim[], int endIndex) {
	ostringstream ss;
	putPathOnBoard(board, dim, endIndex);
	ss << dim[0] << "\n";
	ss << dim[1] << "\n";
	ss << "//path taken \n";
	int currIndex = endIndex;
	int prevIndex;
	int prevLoc[3];
	vector<int> printHelp;
	while(true) {
		if(board[currIndex].cameFrom == -1) {
			break;
		}
		prevIndex = board[currIndex].cameFrom;
		printHelp.push_back(prevIndex);
		currIndex = prevIndex;
	}
	for(int i = printHelp.size() - 1; i >= 0; i--) {
		locationFrIndx(printHelp[i], dim, prevLoc);
		ss << "(" << prevLoc[0] << "," << prevLoc[1] << "," << prevLoc[2] << "," << board[printHelp[i]].type << ")" << "\n";
	}
	cout << ss.str();
}

void printListSln2(vector<square> & board, const int dim[], int endIndex) {
	ostringstream ss;
	int startIndex;
	puthPathOnBoard(board, dim, endIndex, startIndex);
	ss << dim[0] << "\n" << dim[1] << "\n" << "path taken \n";
	int currIndex = startIndex;
	int loc[3];
	while(true) {
		if(board[currIndex].type == "B") {
			break;
		}
		locationFrIndx(currIndex, dim, loc);
		s << "(" << loc[0] << "," << loc[1] << "," << loc[2] << "," << board[printHelp[i]].type << ")" << "\n";
		currIndex = currIndex.cameFrom;
	}
}
