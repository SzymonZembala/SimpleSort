/**
* Sorter.h
*
* Template based Sorter class
*/

#ifndef SORTER_H_
#define SORTER_H_

#include "Array.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

// ------------------------ Sorter Definition ------------------------
template <class T>
class Sorter
{
public:
	Sorter(int size = DEF_SIZE);

	// constructor initialises Sorter using specified Array
	Sorter(const Array<T> & other);

	

	// return capacity of Sorter
	int capacity() const;

	// initialise sorter elements to default values
	void clear();

	// fill Sorter with random numbers
	void fillRandom(int range=100);

	// return copy of Sorter elements
	Array<T> getElements() const;

	// search and sort algorithms
	int binarySearch(const T & value);
	void selectionSort();
	void insertionSort();

	// Load and store elements in a text file
	void loadFile(const std::string & fname);
	void writeFile(const std::string & fname);

	// print elements to specified output stream
	void print(std::ostream & os) const;

private:
	static const int DEF_SIZE=10;
	Array<T> elements;
};

// --------------------------- Sorter Implementation -------------------

// PostCondition: creates a dynamic array of specified size
template <class T>
Sorter<T>::Sorter(int newSize) : elements(newSize) {}

// PostCondition: Sorter member variable 'elements' is initialised
//                with a copy of the specified Array
template <class T>
Sorter<T>::Sorter(const Array<T> & other) : elements(other) {}

// PostCondition: return capacity of Sorter
template <class T>
inline int Sorter<T>::capacity() const
{

	// return the length of the elements array
	return elements.length();

}

// PostCondition: set all Array elements to default value of type T
template <class T>
void Sorter<T>::clear()
{
	// call the elements array initialise function
	elements.initialise();
}

// PostCondition: return a copy of the elements Array instance variable
//                note this invokes the Array copy constructor automatically
//                as we are returning a copy of the elements Array by value
template <class T>
Array<T> Sorter<T>::getElements() const
{
	// return the elements array
	return elements;
}

// PreCondition : elements must have been sorted
// PostCondition: return position if element found, otherwise -1
template <class T>
int Sorter<T>::binarySearch(const T & value)
{
	
	int left = 0, right = used - 1;
	while (left <= right) {
		int pivot = (left + right) / 2;
		cout << "Left=" << left << "	Pivot=" << pivot << "	Right=" << right << endl;
		if (elements[pivot] == element) {
			return pivot;					 //	found
		}
		else {
			if (elements[pivot] < element)
				left = pivot + 1;	 //	search	right
			else
				right = pivot - 1;	 //	search	left
		}
	}
	return -1;
}

// PostCondition: collection elements are sorted
template <class T>
void Sorter<T>::selectionSort() {
	
	
	int min, moves = 0, comps = 0;
	for (int marker = 0; marker < elements.length() - 1; marker++) {
		min = marker;
		for (int i = marker + 1; i < elements.length(); i++) {
			comps++;
			if (elements[i] < elements[min])
				min = i;
		}
		
		moves += 3;
		T	tmp = elements[marker];
		elements[marker] = elements[min];
		elements[min] = tmp;
	}
	cout << "Selection	sort	:	Comps:	" << comps << "	Moves:	" << moves << endl;
}


// PostCondition: collection elements are sorted
template <class T>
void Sorter<T>::insertionSort() {

	
	int comps = 0, moves = 0;
	int in, out, temp;
	for (out = 1; out < elements.length(); out++) {
		temp = elements[out];	 moves++; //	
//	find	position	for	temp
		for (in = out; in > 0 && elements[in - 1] >= temp; in--) {
			elements[in] = elements[in - 1];
			comps++;	moves++; 
		}
		comps++; 
		elements[in] = temp;	moves++; 
	}
	cout << "Insertion	sort	:	Comps:	" << comps << "	Moves:	" << moves << endl;

}

// PostCondition: Sorter filled with max random numbers
template <class T>
void Sorter<T>::fillRandom(int range) {
	for(int i=0; i<elements.length(); i++)
		elements[i] = rand() % range + 1; //convert to 1-range inclusive
}

// Post Condition: Print elements in Sorter to parameter ostream
//                 Could also have simply called the elements print
//                 method  e.g. elements.print(os);
template <class T>
void Sorter<T>::print(std::ostream & os) const {
    
	os << "{	";
	for (int i = 0; i < elements.length(); i++) {
		os << elements[i] << "	";
	}
	os << "}";
}


// PostCondition: overloaded output operator means a Sorter object p
//                is printed to the specified output stream 
template <class T>
std::ostream& operator<< (std::ostream& output, const Sorter<T>& p) {
	

	p.print(output); 
	return output;  
}

// PreCondition: named file exists and contains integers
// PostCondition: array is loaded with integers read from
//                file and array is resized if necessary
template <class T>
void Sorter<T>::loadFile(const std::string & fname) {

	
	std::ifstream	in_stream;
	in_stream.open(fname);
	if (!in_stream.fail()) {
		T	x;
		int i = 0;
		while (in_stream >> x) {
			if (i == elements.length())
				elements.changeSize(elements.length() * 2);	//	double	size	of	array
			elements[i++] = x;
		}
		
		if (i > 0)	elements.changeSize(i);
		in_stream.close();
	}
}


// PreCondition: the specified file can be created
// PostCondition: each element in the sorter is written to
//                the file one element per line
template <class T>
void Sorter<T>::writeFile(const std::string & fname) {
	
	
	std::ofstream	out_stream;
	out_stream.open(fname);
	if (!out_stream.fail()) {
		for (int i = 0; i < elements.length(); i++)
			out_stream << elements[i] << std::endl;
	}
	out_stream.close();
	
}

#endif
