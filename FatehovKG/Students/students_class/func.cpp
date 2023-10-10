#include "Header.h"
student_group::student_group() {
	students = nullptr;
	count = 0;
	cout << "List is empty";
}
istream& operator>>(istream& is, student& students) {
	is >> students.id;
	is >> students.FIO.surname;
	is >> students.FIO.name;
	is >> students.FIO.patronymic;
	is >> students.date.day >> students.date.month >> students.date.year;
	is >> students.number;
	return is;
}
student_group::student_group(const string adress) {
	ifstream file(adress);
	if (!file) {
		cout << "Не удалось открыть файл." << endl;
		exit(1);
	}
	int lineCount = 0;
	string line;

	while (getline(file, line)) {
		lineCount++;
	}
	count = lineCount;
	students = new student[count];
	file.close();
	ifstream base(adress);
	for (int i = 0; i < count; i++) {
		base >> students[i];
	}
	base.close();
}
ostream& operator <<(ostream& os, const student_group& group) {
	for (int i = 0; i < group.count; i++) {
		cout << "student " << group.students[i].id <<" "<< group.students[i].FIO.surname << " " << group.students[i].FIO.name << " " << group.students[i].FIO.patronymic
			<< " " << group.students[i].date.day<< " " << group.students[i].date.month<< " " << group.students[i].date.year<< " " << group.students[i].number<<endl;
	}
	return os;
}
student_group student_group::surname_searh(student_group& students) {
	cout << "enter surname ";
	string surname;
	cin >> surname;
	int counter = 0;
	delete[] this->students;
	this->count = 0;
	for (int i = 0; i < students.count; i++) {
		if (students.students[i].FIO.surname == surname)
			counter++;
	}
	this->count = counter;
	this->students = new student[count];
	if (counter == 0) {
		cout << "\nThere is no one student with this surname\n";
		this->students = nullptr;
		return *this;
	}
	else {
			int j = 0;
		for (int i = 0; i < students.count; i++) {
			if (students.students[i].FIO.surname == surname) {
				this->students[j] = students.students[i];
				j++; 
				if (j == counter) break;
			}
		}
	}
	return *this;
}
student& student::operator=(const student& student) {
	FIO.name = student.FIO.name;
	FIO.surname = student.FIO.surname;
	FIO.patronymic = student.FIO.patronymic;
	date.day = student.date.day;
	date.month = student.date.month;
	date.year = student.date.year;
	id = student.id;
	number = student.number;
	return *this;
}
student_group::student_group(int n) {
	count = n;
	students = new student[count];
}
student_group student_group::phone_searh(student_group& students) {
	cout << "\nenter number ";
	string number;
	cin >> number;
	delete[] this->students;
	this->count = 0;
	for (int i = 0; i < students.count; i++) {
		if (students.students[i].number == number)
		{
			count = 1;
			this->students = new student[count];
			this->students[0] = students.students[i];
			return *this;
		}
		else if (i == students.count - 1) {
			cout << "\nThere is no one student with this number";
			count = 0;
			this->students = nullptr;
			return *this;
		}
	}
}
student_group student_group::bd_search(student_group& students) {
	cout << "\nenter birthday ";
	string day, month, year;
	cin >> day >> month >> year;
	delete[] this->students;
	this->count = 0;
	int count = 0;
	for (int i = 0; i < students.count; i++) {
		if (students.students[i].date.day == day && students.students[i].date.month == month && students.students[i].date.year == year)
			count++;
	}
	if (count == 0) {
		this->count = 0;
		this->students = nullptr;
		cout << "\nThere is no one student with this birthday";
		return *this;
	}
	else {
		this->count = count;
		this->students = new student[count];
		int j = 0;
		for (int i = 0; i < students.count; i++) {
			if  (students.students[i].date.day == day && students.students[i].date.month == month && students.students[i].date.year == year) {
				this->students[j] = students.students[i];
				j++;
				if (j == count) break;
			}
		}
		return *this;
	}
}
student_group::~student_group() {
	delete[] students;
}
void student_group::add_student(string adress) {
	count++;
	ofstream out;
	out.open(adress, ios::app);
	cout << "\nenter new student data:";
	string stud;
	out << count;
	for (int i = 0; i < 7; i++) {
		cin >> stud;
		out <<" "<< stud;
	}
	out << endl;
	out.close();
	delete[] students;
	ifstream file(adress);
	int lineCount = 0;
	string line;
	while (getline(file, line)) {
		lineCount++;
	}
	count = lineCount;
	file.close();
	students = new student[count];
	ifstream base(adress);
	for (int i = 0; i < count; i++) {
		base >> students[i];
	}
	base.close();
}
student_group& student_group::operator=(const student_group& students) {
	count = students.count;
	for (int i = 0; i < count; i++) {
		this->students[i] = students.students[i];
	}
	return *this;
}
student_group student_group::index_search(student_group& students) {
	cout << "\nenter index ";
	string index;
	cin >> index;
	delete[] this->students;
	this->count = 0;
	int count = 0;
	for (int i = 0; i < students.count; i++) {
		if (students.students[i].id == index) {
			count++; break;
		}
	}
	if (count == 0) {
		this->count = 0;
		this->students = nullptr;
		cout << "\nThere is no one student with this index";
		return *this;
	}
	else {
		this->count = count;
		this->students = new student[count];
		int j = 0;
		for (int i = 0; i < students.count; i++) {
			if (students.students[i].id == index) {
				this->students[j] = students.students[i];
				j++;
				if (j == count) break;
			}
		}
		return *this;
	}
}
void student_group::del_student(string adress) {
	cout << "\nenter student index for delete student ";
	int Index;
	cin >> Index;
	std::ifstream inputFile(adress);
	std::ofstream tempFile("temp.txt");
	std::string line;

	int currentIndex = 1;
	while (std::getline(inputFile, line)) {
		int i = 0;
		if (currentIndex != Index) {
			tempFile << line << '\n';
		}
		currentIndex++; ;
	}

	inputFile.close();
	tempFile.close();

	std::remove(adress.c_str());
	std::rename("temp.txt", adress.c_str());
	delete[] students;
	count--;
	students = new student[count];
	ifstream file(adress);
	int lineCount = 0;
	string linee;
	while (getline(file, linee)) {
		lineCount++;
	}
	count = lineCount;
	file.close();
	students = new student[count];
	ifstream base(adress);
	for (int i = 0; i < count; i++) {
		base >> students[i];
	}
	base.close();
}

