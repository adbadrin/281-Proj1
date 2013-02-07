#include <iostream>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include "print.h"
#include "stqu.h"
using namespace std;

char relToPrev(int currIndex, int prevIndex, const int dim[]) {
	int currLoc[3];
	int prevLoc[3];
	locationFrIndx(currIndex, dim, currLoc);
	locationFrIndx(prevIndex, dim, prevLoc);
	if(abs(prevLoc[0] - currLoc[0]) == 1) {
		if(prevLoc[0] - currLoc[0] == 1) {
			return 'n';
		}
		else {
			return 's';
		}
	}
	if(abs(prevLoc[1] - currLoc[1]) == 1) {
		if(prevLoc[1] - currLoc[1] == 1) {
			return 'w';
		}
		else {
			return 'e';
		}
	}
	return 'p';
}


	
void putPathOnBoard(vector<square>& board, const int dim[], const int& endIndex) {
	int currIndex = endIndex;
	int prevIndex;
	char prevDir;
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
	int prevIndex = board[currIndex].cameFrom;
	int temp;
	char prevDir;
	while(true) {
		if(prevIndex == -1) {
			break;
		}
		temp = board[prevIndex].cameFrom;
		prevDir = relToPrev(currIndex, prevIndex, dim);
		board[prevIndex].type = prevDir;
		board[prevIndex].cameFrom = currIndex;
		currIndex = prevIndex;
		prevIndex = temp;
	}
	startIndex = currIndex;
}

void printListSln(vector<square> & board, const int dim[], int endIndex) {
	ostringstream ss;
	int startIndex;
	putPathOnBoard2(board, dim, endIndex, startIndex);
	ss << dim[0] << "\n" << dim[1] << "\n" << "//path taken \n";
	//cout << dim[0] << "\n" << dim[1] << "\n" << "//path taken \n";
	int currIndex = startIndex;
	int loc[3];
	while(true) {
		if(board[currIndex].type == 'B') {
			break;
		}
		locationFrIndx(currIndex, dim, loc);
		ss << "(" << loc[0] << "," << loc[1] << "," << loc[2] << "," << board[currIndex].type << ")" << "\n";
		//cout << "(" << loc[0] << "," << loc[1] << "," << loc[2] << "," << board[currIndex].type << ")" << "\n";
		currIndex = board[currIndex].cameFrom;
	}
	cout << ss.str();
}
