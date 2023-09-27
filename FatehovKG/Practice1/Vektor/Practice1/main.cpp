#include "Header.h"
int main() {
	cout << "Input vector i: ";
	Vector i, j;
	cin >> i;
	cin >> j;
	double len = i.vector_length();
	cout <<"Length i(" <<i <<"):" << len << endl;
	double len2 = j.vector_length();
	cout << "Length j(" << j << "):" << len2 << endl;
	cout << "i+j " << i + j << endl;
	cout << "i-j " << i - j << endl;
	cout << "i*j " << i * j << endl;
	cout << "cos(i,j) " << i.cos(j) << endl;
	
	return 0;
}