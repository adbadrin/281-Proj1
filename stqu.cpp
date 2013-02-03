#include "build.h"
#include <queue>
using namespace std;

bool getSqAtDir(int index, const int dim[], int& neigh, dir card) {
	int proposed[3];
	locationFrIndx(index, dim, proposed);
	switch ((int)card) {
		case 0:
			proposed[1] += 1;
		case 1:
			proposed[0] += 1;
		case 2:
			proposed[1] -= 1;
		case 3:
			proposed[0] -= 1;
	}
	if((proposed[0] >= dim[0]) || (proposed[1] >= dim[1]) || (proposed[0] < 0) || (proposed[1] < 0)) {
		return false;
	}
	indexFrLoc(proposed, dim, neigh);
	return true;
}

void addToQ(vector<square> board,  queue<square> decider, int dim[]) {
	int adIndex;
	int index = (decider.front()).index;
	if(isdigit(board[index].type[0])) {
		//adIndex = portal function;
		board[adIndex].cameFrom = index;
		decider.push(board[adIndex]);
	}
	else {
		for(int i = 0; i < 4; i++) {
			if(getSqAtDir(index, dim, adIndex, dir(i))) {
				board[adIndex].cameFrom = index;
				decider.push(board[adIndex]);
			}
		}
	}
	decider.pop();
}



			
