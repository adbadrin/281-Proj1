#ifndef STQU_H
#define STQU_H
#include "build.h"
#include <deque>

bool getSqAtDir(int index, const int dim[], int& neigh, dir card);

void genPush(std::deque<int>& decider, int& adIndex, bool useStack); 


void nextMove(std::vector<square>& board, std::deque<int>& decider, const int dim[], bool useStack); 

#endif
