#include <iostream>
#include <sstream>
using namespace std;

string relToPrev(vector<square>& board, int currIndex, int prevIndex, const int dim[]) {
	int currLoc[3];
	int prevLoc[3];
	locationFrIndx(currIndex, dim, currLoc);
	locationFrIndx(prevIndex, dim, prevLoc);
	if(abs(prevLoc[0] - currLoc[0]) == 1) {
		if(prevLoc[0] - currLoc[0] == 1) {
			return "e";
		}
		else {
			return "w";
		}
	}
	if(abs(prevLoc[1] - currLoc[1]) == 1) {
		if(prevLoc[1] - currLoc[1] == 1) {
			return "s";
		}
		else {
			return "n";
		}
	}
	return "p";
}


	
void putPathOnBoard(vector<square& board, const int dim[], const int endIndex) {
	int currIndex = endIndex;
	int prevIndex;
	string prevDir;
	while(true) {
		if(board[currIndex].cameFrom == -1) {
			break;
		}
		prevIndex = board[currIndex].cameFrom;
		prevDir = relToPrev(board, currInd, prevIndex, dim);
		board[prevIndex].type = prevDir;
	}
}


void printMapSln(vector<square>& board, deque<square>& decider, const int dim[], int endIndex) {
	ostringstream ss;
	int floor;
	putPathOnBoard(board, dim, endIndex);
	for(int i = 0; i < board.size(); i++) {
		if((i!=0) && (i % dim[0] == 0)) {
			ss << '\n';
		}
		if((i!=0) && (i & (dim[0] * dim[0]) == 0)) {
				floor = i/(dim[0] * dim[0]) - 1;
				ss << "//room " << floor << "\n";
		}
		ss << board[i].type;
	}
	floor =  i/(dim[0] * dim[0]) - 1;
	ss << "//room " << floor << "\n";
	ss << dim[1] << "\n";
	ss << dim[0] << "\n";
	cout << ss.str();
}

void printList(std::vector<square>& board, const int dim[], int endIndex) {
	ostringstream ss;
	putPathOnBoard(board, dim, endIndex);
	int currIndex = endIndex;
	int prevIndex;
	int prevLoc[3]
	while(true) {
		if(board[currIndex].cameFrom == -1) {
			break;
		}
		prevIndex = board[currIndex].cameFrom;
		locationFrIndx(prevLoc, dim, prevIndex);
		ss << "(" << prevLoc[0] << "," << prevLoc[1] << "," << 	prevLoc[2] << "," << board[prevIndex].type << ")" << "\n";
	}
	cout << ss.str();
}
