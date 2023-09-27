#include "Header.h"
int main() {
	Vector i(1,1,1);
	double len = i.vector_length();
	cout << len<<endl;
	Vector j (-1,2,-2);
	 i =i+ j;
	len = i.vector_length();
	cout << len;
	return 0;
}