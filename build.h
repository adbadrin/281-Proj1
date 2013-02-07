#ifndef BUILD_H
#define BUILD_H
#include<vector>


enum dir {NORTH, EAST, SOUTH, WEST};

struct square {
	square() : type('.'), cameFrom(-1) {}
	char type;
	int index;
	int cameFrom;
};

bool buildFromMap(std::vector<square>& board, int dim[], int& startIndex);

bool buildFromList(std::vector<square> &board, int dim[], int& startIndex);

void locationFrIndx(const int& index, const int dim[], int loc[]);

void indexFrLoc(const int loc[], const int dim[], int& index);

#endif

