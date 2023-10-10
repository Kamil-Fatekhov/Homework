#include "Header.h"

int main() {
	Vector<int> v(3);   // Создание вектора размером 3
	cin >> v;      // Ввод элементов вектора (например, 1 2 3)
	Vector<int> c(4);
	cin >> c;
	double b; 
	b = c * v;
	cout << b;
}