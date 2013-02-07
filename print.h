#ifndef PRINT_H
#define PRINT_H
#include "build.h"

char relToPrev(int currIndex, int prevIndex, const int dim[]);

void printMapSln(std::vector<square>& board, const int dim[], int endIndex, bool putPath);

void printListSln(std::vector<square>& board, const int dim[], int endIndex);

void printListSln2(std::vector<square>& board, const int dim[], int endIndex);

void putPathOnBoard(std::vector<square>& board, const int dim[], const int& endIndex);

void putPathOnBoard2(std::vector<square>& board, const int dim[], const int& endIndex, int& startIndex);

#endif
