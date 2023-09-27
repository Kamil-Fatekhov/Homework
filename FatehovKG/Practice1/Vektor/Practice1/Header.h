#pragma once
#include <iostream>
#include <math.h>

using namespace std;
class Vector;

class Vector {
public:
	Vector();
	Vector(float x, float y, float z);
	Vector operator+(Vector& other);
	Vector operator-(Vector& other);
	friend ostream& operator<<(ostream& os, const Vector& vector);
	friend istream& operator>>(istream& input, Vector& vector);
	const Vector& operator=(const Vector& other);
	float operator*(Vector& other) const;
	float cos(Vector& other) const;
	double vector_length() const;
private:
	float x;
	float y;
	float z;
};