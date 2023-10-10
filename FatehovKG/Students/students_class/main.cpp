#include "Header.h"
int main() {
	setlocale(LC_ALL, "rus");
const string adress = "studeent.txt";
student_group group(adress);
cout << group;
group.add_student(adress);
cout << group;
student_group students = students.surname_searh(group);
cout << students;
student_group students_phone = students_phone.phone_searh(group);
cout << students_phone;
student_group students_bd = students_bd.bd_search(group);
cout << students_bd;
student_group id_search = id_search.index_search(group);
cout << id_search;
group.del_student(adress);
cout << group;
	return 0;
}