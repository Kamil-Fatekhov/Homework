#include "header.h"

int* array_create(int n) {
	int* arr = new int[n];
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % (10-1);
	}
	return arr;
}
void array_out(int* arr, int n) {

	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
}
int unique(int* arr, int n) {
	
	int i = 1;
	int j = 1;
	int flag = 0;
	while (i < n) {
		while(flag < j) {
			if (arr[flag] == arr[i]) {
				flag = 0; i++; if (i == n) break;
			}
			else {
				if (flag == j - 1 && arr[flag] != arr[i]) {
					arr[j] = arr[i]; j++; flag = 0; i++;
					if (i == n) break;

				}
				else flag++;
			}

			//j++;
		}
	}
		return j;
}
int* new_arr(int* arr, int n, int uniq) {
	int* arr_new = new int[uniq];
	arr_new[0] = arr[0];
	int i = 1;// фиксированный элемент начального массива
	int j = 1;// длина нового массива
	int flag = 0;
	while (i < n) {
		while (flag < j) {
			if (arr_new[flag] == arr[i]) {
				flag = 0; i++; if (i == n) break;// сравниваем элементы нового массива с элементами старого, при совападении переходим к новому фиксированному числу начального массива
			}
			else {
				if (flag == j - 1 && arr_new[flag] != arr[i]) {
					arr_new[j] = arr[i]; j++; flag = 0; i++; // если элемент нового, не равен элементу начального и при этом элемент последний в массиве, то записываем новый элем нач массива
					if (i == n) break;

				}
				else flag++;// иначе проверяем следующий элемент исходного
			}

			//j++;
		}
	}
	return arr_new;
}