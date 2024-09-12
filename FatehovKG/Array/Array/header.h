#pragma once
#include <iostream>

using namespace std;

class Array {
private:
	int* array;
	int count;
	int size;
public:
	Array();
	~Array();
	Array(int size);
	void append(int elem);
	bool search(int elem);
	int GetMin();
	int GetMax();
	void print();
};