#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct FIO {
	string surname;
	string name;
	string patronymic;
};
struct date_of_birth {
	string day;
	string month;
	string year;
};
struct student {
	FIO FIO;
	date_of_birth date;
	string number;
	string id;
	student& operator = (const student& student);
};
class student_group {
private:
	student* students;
	int count;
public:
	student_group();
	~student_group();
	student_group(int n);
	student_group(const string adress);
	void add_student(string adress);
	void del_student(string adress);
	student_group surname_searh(student_group& students);
	student_group phone_searh(student_group& students);
	student_group bd_search(student_group& students);
	student_group& operator=(const student_group& students);
	student_group index_search(student_group& students);
friend ostream& operator <<(ostream& os, const student_group& group);
friend istream& operator >>(istream& is, student& students);
};