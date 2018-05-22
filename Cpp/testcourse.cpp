#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include "course.h"
using namespace std;
int main(void) {
	int a;
	Course course1("Data_Structure", 10);//构建class的实例对象，并初始化
	Course course2("Database_Systems", 15);

	course1.addStudent("PJ");
	course1.addStudent("BS");
	course1.addStudent("AK");

	course2.addStudent("PJ");
	course2.addStudent("SS");

	cout << "Number of student in course1:" << course1.getNumberOfStudents() << "\n";
	string* students = course1.getStudent();
	course1.printStudent();

	cout << " \n Number of students in course2:" << course2.getNumberOfStudents() << "\n";

	students = course2.getStudent();
	course2.printStudent();

	course1.dropStudent("BS");
	course1.printStudent();
	return 0;
}