#include <iostream>   // gets cin, cout, cerr
#include <fstream>    // gets file functions of open and close
#include <string.h>   // gets the string type, which is part of std namespace

#include "p7.h"

using namespace std;

//******************************************************************************

int const OneMillion = 1000000;

void
doWork1(intList *list, int sortMethod) {
    // sortMethod = 0 for bubble, 1 for selection, 2 for insertion
	int i, v;
	bool rc;
	list->clear();
	for (i = 0; i < list->capacity(); i++) {
		list->add(20 - i);
	}
	rc = list->insert(10);
	cout << list->capacity() << "\n";
	list->bubbleSort();
	list->printIt(20);
}

int
main(int argc, char *argv[]) {
    intList *myL;
    int n;

    if (argc < 2) {
	cerr << "Usage: p7 n  -- where n is the size of the list\n";
	exit(-1);
    }
    sscanf(argv[1], "%d", &n);

    cout << "n = " << n << endl;

    myL = new intList(n);

    doWork1(myL, 0);
}
