//==============================================================================
// Name        : practical3.cpp

// Description : test program to exercise the simple sort algorithms
//==============================================================================

#include <string>
#include <cctype>
#include "Array.h"
#include "Sorter.h"
#include <time.h>       /* time */

using namespace std;

// test selection sort
void testSelect() {
	Sorter<int>	data(20);
	data.fillRandom();
	cout << "Select	Unsorted:	" << data << endl;
	data.selectionSort();
	cout << "Select	Sorted		:	" << data << endl << endl;

}

// test insertion sort
void testInsert() {
	Sorter<int>	data(20);
	data.fillRandom();
	cout << "Insert	Unsorted:	" << data << endl;
	data.insertionSort();
	cout << "Insert	Sorted		:	" << data << endl;
	cout << "Insert	Resorted:	";
	data.insertionSort();
	cout << endl;

}

// Test Both Sorts sorting same data
void testBoth() {
	
	Sorter<int>	insert(20);
	Sorter<int>	select(20);
	insert.fillRandom();
	insert.writeFile("unsorted.txt");
	select.loadFile("unsorted.txt");
	cout << "Select	Unsorted:	" << select << endl;
	cout << "Insert	Unsorted:	" << insert << endl;
	insert.insertionSort();
	select.selectionSort();
	cout << endl;
	cout << "Select	Sorted:	" << select << endl;
	cout << "Insert	Sorted:	" << insert << endl << endl;
}

// test string sorting
void testString() {
	Array<string>	strings(10);
	for (int i = 0; i < strings.length(); i++) {
		cout << "Enter	string	" << i << ":	";
		cin >> strings[i];
	}
	Sorter<string>	sorter(strings);
	cout << "Unsorted	:	" << sorter << endl;
	sorter.selectionSort();
	cout << "Sorted			:	" << sorter << endl;
	
}

// Main method.
int main() {
    /* initialize random seed: */
    srand (time(NULL));

	// call test methods here
	//testSelect();
	//testInsert();
	testBoth();
	testString();

	// ---------------------------------------------------
	cout << endl << "Press enter to quit";
	cin.get();
	return 0;
}