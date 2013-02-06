#include <cstdlib>
#include "stque.h"
using namespace std;

bool getSqAtDir(int index, const int dim[], int& neigh, dir card) {
	int proposed[3];
	locationFrIndx(index, dim, proposed);
	switch ((int)card) {
		case 0:
			proposed[0] -= 1;
			break;
		case 1:
			proposed[1] += 1;
			break;
		case 2:
			proposed[0] += 1;
			break;
		case 3:
			proposed[1] -= 1;
			break;
	}
	if((proposed[0] >= dim[0]) || (proposed[1] >= dim[0]) || (proposed[0] < 0) || (proposed[1] < 0)) {
		return false;
	}
	indexFrLoc(proposed, dim, neigh);
	return true;
}

void genPush(deque<int>& decider, int& adIndex, bool useStack) {
	if(useStack) {
		decider.push_front(adIndex);
	}
	else {
		decider.push_back(adIndex);
	}
}


void nextMove(vector<square>& board, deque<int>& decider, const int dim[], bool useStack) {
	int adIndex;
	int index = decider.front;
	decider.pop_front();
	if(isdigit(board[index].type[0])) {
		int loc[3];
		locationFrIndx(index, dim, loc);
		loc[2] = atoi(board[index].type.c_str());
		if(loc[2] >= dim[1]) {}
		else {
			indexFrLoc(loc, dim, adIndex);
			if (board[adIndex].type == "#") {}
			else if(board[adIndex].cameFrom != -1) {}
			else {
				board[adIndex].cameFrom = index;
				genPush(decider, adIndex, useStack);
			}
		}
	}
	else {
		for(int i = 0; i < 4; i++) {
			if(getSqAtDir(index, dim, adIndex, dir(i))) {
				if(board[adIndex].type == "#") {}
				else if(board[adIndex].cameFrom != -1) {}
				else if(board[adIndex].type == "S") {}
				else {
					board[adIndex].cameFrom = index;
					genPush(decider, adIndex, useStack);
					if(board[decider.front()].type == "B") {
						break;
					}
				}
			}
		}
	}
}
