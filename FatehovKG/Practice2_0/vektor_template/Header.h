#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T>
class Vector {
private:
	T* vec; int size;
public:
	Vector(int size);
	Vector(const Vector <T>& obj);
	Vector();
	Vector <T> operator+ (const Vector <T>& obj);
	Vector <T> operator- (const Vector <T>& obj);
	double operator* (const Vector <T>& obj) const;
	double length() const;
	bool operator == (const Vector <T>& obj) const;
	bool operator != (const Vector <T>& obj) const;
	Vector <T>& operator = (const Vector <T>& obj);
	friend istream& operator >> (istream & in, Vector <T> obj);
	friend ostream& operator << (ostream & os, const Vector <T> obj);
};

template <typename T>
Vector <T>::Vector(const Vector <T>& obj) {
	size = obj.size;
	vec = new T[size];
	for (int i = 0; i < size; i++) {
		vec[i] = obj.vec[i];
	}
}

template <typename T>
Vector <T>::Vector(int size) {
	this->size = size;
	vec = new T[size];
}

template <typename T>
Vector <T>::Vector() {
	size = 0;
}

template <typename T>
Vector <T >Vector <T>:: operator+(const Vector <T>& obj) {
	if (size != obj.size)
		throw;
	for (int i = 0; i < size; i++) {
		vec[i] += obj.vec[i];
	}
	return *this;
}

template <typename T>
bool Vector <T>::operator==(const Vector <T>& obj)const {
	if (size != obj.size)
		throw;
	int flag = 0;
	for (int i = 0; i < size; i++) {
		if (vec[i] != obj.vec[i])
			flag++;
		break;
	}
	if (flag == 0)
		return true;
	return false;
}

template <typename T>
bool Vector <T>::operator!=(const Vector <T>& obj)const {
	return !(this == obj);
}

template <typename T>
Vector <T>& Vector<T>::operator=(const Vector <T>& obj) {
	if (this == obj)
		return this;
	if (size != obj.size) {
		delete[] vec;
		size = obj.size;
		vec = new T[size];
	}
	for (int i = 0; i < size; i++) {
		vec[i] = obj.vec[i];
	}
	return *this;
}

template <typename T>
Vector <T >Vector <T>:: operator-(const Vector <T>& obj) {
	if (size != obj.size)
		throw;
	for (int i = 0; i < size; i++) {
		vec[i] -= obj.vec[i];
	}
	return *this;
}

template <typename T>
double Vector <T>::operator*(const Vector <T>& obj)const {
	if (size != obj.size)
		throw;
	double res = 0;
	for (int i = 0; i < size; i++) {
		res += vec[i] * obj.vec[i];
	}
	return res;
}

template <typename T>
double Vector <T>::length() const {
	double res = 0;
	for (int i = 0; i < size; i++) {
		res += vec[i] * vec[i];
	}
	return sqrt(res);
}

template <typename T>
istream& operator >> (istream& in,  Vector <T> obj) {
	cout << "Input size: ";
	in >> obj.size;
	cout << endl;
	obj.vec = new T[obj.size];
	for (int i = 0; i < obj.size; i++) {
		in >> obj.vec[i];
	}
	return in;
}

template <typename T>
ostream& operator << (ostream& os, const Vector <T> obj) {
	os << "Size: " << obj.size << endl;
	for (int i = 0; i < obj.size; i++) {
		os << "Vec[" << i << "] = " << obj.vec[i] << endl;
	}
	return os;
}