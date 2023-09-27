#include "Header.h"
Vector::Vector() {
	x = y = z = 0;
}
Vector::Vector(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}
Vector Vector::operator+(Vector& other) {
	Vector res;
	res.x = x + other.x;
	res.y = y + other.y;
	res.z = z + other.z;
	return res;
}
ostream& operator<< (ostream& os, const Vector& vector) {
	os <<   vector.x <<   " " << vector.y <<  " " << vector.z;
	return os;
}
Vector Vector::operator-(Vector& other) {
	Vector res;
	res.x = x - other.x;
	res.y = y - other.y;
	res.z = z - other.z;
	return res;
}
double Vector::vector_length() const {
	return sqrt(x * x + y * y + z * z);
}
const Vector& Vector::operator=(const Vector& other) {
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}
float Vector::operator*(Vector& other) const {
	return other.x * x + other.y * y + other.z * z;
}
float Vector::cos(Vector& other) const{
	return (*this * other) / (this->vector_length() * other.vector_length());
}
istream& operator>> (istream& input, Vector& vector) {
	input >> vector.x >> vector.y >> vector.z;
	return input;
}