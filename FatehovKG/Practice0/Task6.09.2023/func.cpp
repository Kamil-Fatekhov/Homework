#include "header.h"
float* create_array(int n) {
	float* arr = new float[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		arr[i] = ((float(rand()) / float(RAND_MAX)) * (15-0)  );
	}
	return arr;
}
float* array_sqr(float* arr, int n) {
	float* array_new = new float[n];
	for (int i = 0; i < n; i++) {
		if (arr[i] > 10)
			array_new[i] = arr[i] * arr[i];
		else
			array_new[i] = arr[i];
	}
	return array_new;
}
void array_out(float* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
}