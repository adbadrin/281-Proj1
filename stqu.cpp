#include "stqu.h"
#include <deque>
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

void genPush(vector<square>& board, deque<square>& decider, int& adIndex, bool& useStack) {
	if(useStack) {
		decider.push_front(board[adIndex]);
	}
	else {
		decider.push_back(board[adIndex]);
	}
}

bool nextMove(vector<square>& board, deque<square>& decider, int dim[], bool useStack) {
	int adIndex;
	if(!(decider.empty())) {
		int index = (decider.front()).index;
		if(isdigit(board[index].type[0])) {
			/*
			 * adIndex = portalFunction
			 * board[adIndex].cameFrom = index
			 * genPush(board, decider, useStack, adIndex);
			 */
		}
		else {
			for(int i = 0; i < 4; i++) {
				if(getSqAtDir(index, dim, adIndex, dir(i))) {
					board[adIndex].cameFrom = index;
					genPush(board, decider, adIndex, useStack);
				}
			}
		}
		decider.pop_front();
		return true;
	}
	return false;
}



			
