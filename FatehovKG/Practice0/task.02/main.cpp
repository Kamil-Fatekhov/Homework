#include "header.h"
int main() {
	int n = numbers();
	int* initial_arr = array_create(n);
	array_out(initial_arr,n);
	initial_arr = swap(initial_arr,n);
	cout << endl;
	array_out(initial_arr,n);
	delete[] initial_arr;
	return 0;
}