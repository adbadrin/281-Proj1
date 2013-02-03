#include "build.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <getopt.h>
using namespace std;

int main(int argc, char* argv[]) {
	vector<square> board; 
	int startIndex;
	int dim[2];
	if(buildFromList(board, dim, startIndex)) {
		printMap(board, dim);
	}
	/*
	queue<square> path;
	queue<square> decideQ;
	stack<square> decideS;
	int c = 0;
	bool useStack = false;
	bool useQueue = false;
	bool mapOut = true;
	int startIndex;
	string s;
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
				return 1;
				break;

			case '?':
				cout << "Invalid option. \n";
				return 0;
				break;

			default:
				break;
		}
	}
	if(useStack && useQueue) {
		cerr << "You can't select both stacks AND queues! \n";
		return 0;
	}
	getline(cin, s);
	if(s == 'M') {
		if(!(buildFromMap(board, dim))) {
			cerr << "Bad (map) input! \n";
			return 1;
		}
	}
	else {
		if(!(buildFromList(board, dim))) {
			cerr << "Bad (list) input! \n";
			return 1;
		}
	}
	if(useStack) {
		decideQ.push_back(board[startIndex]);
		while(true) {
			if(path.back().type == "B") {
				//We Made It Home!
				break;
			}
			if(decideQ.empty()) {
				//No more possible options... we're hosed!
				break;
			}
			addToQueue(board, path, decider, dim);
		}
	}
	*/
}

				

