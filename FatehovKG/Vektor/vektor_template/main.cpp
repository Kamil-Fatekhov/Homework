#include "Header.h"

int main() {
	Vector<int> v(3);   // �������� ������� �������� 3
	cin >> v;      // ���� ��������� ������� (��������, 1 2 3)
	Vector<int> c(4);
	cin >> c;
	double b; 
	b = c * v;
	cout << b;
}