#ifndef STQU_H
#define STQU_H
#include "build.h"

bool getSqAtDir(int index, const indim[], int& neigh, dir card);


void genPush(vector<square>& board, deque<square>& decider, int& adIndex, bool useStack); 


bool nextMove(vector<square>& board, deque<square>& decider, int dim[], bool useStack); 

#endif
