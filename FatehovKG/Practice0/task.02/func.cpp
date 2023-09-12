#include "header.h"

int* array_create(int n) {
	int* arr = new int[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % (100 - 10);
	}
	return arr;
}
void array_out(int* arr,int n ) {
	
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
}
int* swap(int* arr,int n) {
	int end = n-1;
	int middle = n/2-1;
		int flag = 0;
		int tmp;
		do {
			tmp = arr[end - flag];
			arr[end - flag] = arr[middle - flag];
			arr[middle - flag] = tmp;
			flag++;
		} while (end - flag != middle);
	return arr;
}
int numbers() {
	int n;
	do {
		cout << "Enter an even number of elements ";
		cin >> n;
	} while (n % 2 != 0);
	return n;
}