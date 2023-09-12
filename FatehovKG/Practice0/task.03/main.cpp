#include "header.h"
int main() {
	int n;
	cout << "Enter array length ";
	cin >> n;
	int* initial_arr = array_create(n);
	array_out(initial_arr, n);
	 int uniq = unique(initial_arr, n);
	cout << endl;
	int* arr_new = new_arr(initial_arr, n, uniq);
	array_out(arr_new, uniq);
	delete[] arr_new;
	delete[] initial_arr;
	return 0;
}