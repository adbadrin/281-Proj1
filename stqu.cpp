#include <cstdlib>
#include "stqu.h"
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

void genPush(vector<square>& board, deque<square>& decider, int& adIndex, bool useStack) {
	if(useStack) {
		decider.push_front(board[adIndex]);
	}
	else {
		decider.push_back(board[adIndex]);
	}
}


void nextMove(vector<square>& board, deque<square>& decider, const int dim[], bool useStack) {
	int adIndex;
	int index = (decider.front()).index;
	if(isdigit(board[index].type[0])) {
		/*
		 * adIndex = portalFunction
		 * board[adIndex].cameFrom = index
		 * genPush(board, decider, useStack, adIndex);
		 */
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
				genPush(board, decider, adIndex, useStack);
			}
		}
	}
	else {
		for(int i = 0; i < 4; i++) {
			if(getSqAtDir(index, dim, adIndex, dir(i))) {
				if(board[adIndex].type == "#") {}
				}
				else if(board[adIndex].cameFrom != -1) {}
				else {
					board[adIndex].cameFrom = index;
					genPush(board, decider, adIndex, useStack);
				}
			}
		}
	decider.pop_front();
}
