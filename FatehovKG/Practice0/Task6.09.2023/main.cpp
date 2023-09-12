#include "header.h"

int main() {
	int n;
	cout << "Input array length ";
	cin >> n;
	float* array1 = create_array(n);
	array_out(array1,n);
	cout << endl;
	float* array_new = array_sqr(array1,n);
	array_out(array_new,n);
	delete[] array1;
	delete[] array_new;
	return 0;
}