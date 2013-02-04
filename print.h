#ifndef PRINT_H
#define PRINT_H
#include "build.h"
#include "sstream"

std::string relToPrev(vector<square>& board, int currIndex, int prevIndex, const int dim[]);

void printMapSln(std::vector<square>& board, const int dim[], int endIndex);

void printList(std::vector<square>& board, const int dim[], int endIndex);

#endif
