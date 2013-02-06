#include "build.h"
#include "print.h"
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

/*
void locationFrIndx(const int&index, const int dim[], int loc[]) {
	loc[2] = dim[1] - 1 - index/(dim[0] * dim[0]);
	loc[1] = index % dim[0];
	loc[0] = (index - (dim[1] - 1 - loc[2]) * (dim[0] * dim[0])) / dim[0];
}

*/

void buildCordMap() {
	char specAr[35] = {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '#', '#', '#', '#', '#', '#', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	int dim[2];
	//dim[0] = rand() % 100 + 1;
	dim[0] = 1000;
	//dim[1] = rand() % 10 + 1;
	dim[1] = 10;
	int loc[3];
	ostringstream ss;
	ss << "L \n";
	ss << dim[0] << "\n";
	ss << dim[1] << "\n";
	int startIndex = rand() % (dim[0] * dim[0] * dim[1]);
	int endIndex = rand() % (dim[0] * dim[0] * dim[1]);
	int charDet;
	for(int i = 0; i < dim[0] * dim[0] * dim[1]; i++) {
		charDet = rand() % 35;
		locationFrIndx(i, dim, loc);
		if(i == startIndex) {
				ss << "(" << loc[0] << "," << loc[1] << "," << loc[2] << "," << "S" << ")" << "\n";
		}
		else if (i == endIndex) {
				ss << "(" << loc[0] << "," << loc[1] << "," << loc[2] << "," << "B" << ")" << "\n";
		}
		else {
			ss << "(" << loc[0] << "," << loc[1] << "," << loc[2] << "," <<  specAr[charDet] << ")" << "\n";
		}
	}
	cout << ss.str();
}
/*
void printList(vector<square>& board, int dim[]) {
	int loc[3];
	ostringstream ss;
	ss << dim[0] << "\n";
	ss << dim[1] << "\n";
	for(int i = 0; i < board.size(); i++) {
		locationFrIndx(i, dim, loc);
		ss << "(" << loc[0] << "," << loc[1] << "," << loc[2] << "," << board[i].type << ")" << "\n";
	}
	cout << ss.str();
}
*/



int main() {
	buildCordMap();
	/*
	vector<square> board;
	int dim[2];
	int startIndex;
	buildFromList(board, dim, startIndex);
	printMapSln(board, dim, -1, false);
	*/
}




	
