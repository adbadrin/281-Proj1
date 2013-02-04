#ifndef PRINT_H
#define PRINT_H
#include "build.h"

std::string relToPrev(std::vector<square>& board, int currIndex, int prevIndex, const int dim[]);

void printMap(const vector<square>& board, int dim[]);

void printMapSln(std::vector<square>& board, const int dim[], int endIndex);

void printListSln(std::vector<square>& board, const int dim[], int endIndex);

void putPathOnBoard(std::vector<square>& board, const int dim[], const int& endIndex);

#endif
