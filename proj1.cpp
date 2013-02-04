#include <cstdlib>
#include <iostream>
#include <sstream>
#include <getopt.h>
#include "build.h"
#include "stqu.h"
#include "print.h"
using namespace std;

int main(int argc, char* argv[]) {
	vector<square> board; 
	deque<square> decider;
	int c = 0;
	bool useStack = false;
	bool useQueue = false;
	bool mapOut = true;
	int startIndex;
	int endIndex;
	string s;
	int dim[3];
	while(c != -1){
		const struct option long_options[] = {
			{"stack", 0, 0, 's'},
			{"queue", 0, 0, 'q'},
			{"output", 1, 0, 'o'},
			{"help", 0, 0, 'h'},
			{0, 0 , 0, 0}
		};
		int option_index = 0;
		c = getopt_long(argc, argv, "sqoh", long_options, &option_index);
		switch (c) {

			case 's':
				useStack = true;
				break;

			case 'q':
				useQueue = true;
				break;

			case 'o':
				if(*optarg == 'L') {
					mapOut = false;
				}
				else {
				}
				break;

			case 'h':
				cout << "This does something. \n";
				return 0;
				break;

			case '?':
				cout << "Invalid option. \n";
				return 1;
				break;

			default:
				break;
		}
	}
	if(useStack && useQueue) {
		cerr << "You can't select both stacks AND queues! \n";
		return 1;
	}
	if(!useStack && !useQueue) {
		cerr <<"You have to select at ONE of stacks or queues! \n";
		return 1;
	}
	getline(cin, s);
	if(s == "M") {
		if(!(buildFromMap(board, dim, startIndex))) {
			cerr << "Bad (map) input! \n";
			return 1;
		}
	}
	else {
		if(!(buildFromList(board, dim, startIndex))) {
			cerr << "Bad (list) input! \n";
			return 1;
		}
	}
	decider.push_front(board[startIndex]);
	while((!decider.empty()) && !(decider.front().type == "B")) {
		nextMove(board, decider, dim, useStack);
	}
	if(decider.empty()) {
		if(mapOut) {
			printMap(board, dim);
		}
		else {
			cout << dim[0] << "\n" << dim[1] << "\n" << "//path taken" << "\n";
		}
		return 0;
	}
	endIndex = decider.front().index;
	if(mapOut) {
		printMapSln(board, dim, endIndex);
	}
	/*else {
		printListSln(board, dim, endIndex);
	}
	*/
}

				

