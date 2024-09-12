#include "header.h"
Array::Array() {
	count = 0;
	size = 0;
	array = new int[size];
}
Array::Array(int size) {
	this->size = size;
	count = 0;
	array = new int[size];
}
void Array::append(int elem) {
  if (count == size) {
    // Увеличить размер массива в два раза
    size = 2; 
    int* newArray = new int[size]; 

    // Скопировать элементы в новый массив
    for (int i = 0; i < count; ++i) {
      newArray[i] = array[i];
    }

    // Удалить старый массив
    delete[] array;
    array = newArray;
  }

  // Добавить новый элемент
  array[count++] = elem;
}
bool Array::search(int elem) {
	for (int i = 0; i < size; i++) {
		if (elem == array[i]) return true;
	}
	return false;
}
int Array::GetMax() {
	int n = array[0];
	for (int i = 0; i < size; i++) {
		if (n < array[i]) n = array[i];
	}
	return n;
}
int Array::GetMin() {
	int n = array[0];
	for (int i = 0; i < size; i++) {
		if (n > array[i]) n = array[i];
	}
	return n;
}
Array::~Array() {
	delete[] array;
}
void Array::print() {
	for (int i = 0; i < size; i++)
		cout << array[i] << endl;
}