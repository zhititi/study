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
Course::Course(const string&courseName, int Capacity)  //ͬ���ĳ�ʼ������
{
	numberOfStudent = 0;
	this->courseName = courseName;
	this->Capacity = Capacity;
	student = new string[Capacity];
}

Course::~Course() {  //::ǰ�ı�����class����namespace
	delete[]student;
}

string Course::getCoureName() const  //���const��ʾ������privateֵ
{
	return courseName;
}

void Course::addStudent(const string& name)
{
	if (numberOfStudent < Capacity)
	{
		student[numberOfStudent] = name;
		numberOfStudent++;
	}
	else {
		cout << "ѧ��̫����" << endl;
		return;
	}

}
void Course::dropStudent(const string& name)
{
	//  
	string* pFindName = find(student, student + numberOfStudent, name);
	if (pFindName != student + numberOfStudent)
	{
		cout << "this student has been found" << "at position" << " " << pFindName - student << endl;
		int postion = pFindName - student;
		for (int i = postion + 1; i < numberOfStudent; i++) {
			student[i - 1] = student[i];
		}
		numberOfStudent--;
	}
	else {
		cout << name << "is not found" << endl;
	}
}
string* Course::getStudent() const
{
	return student;
}

int Course::getNumberOfStudents() const {
	return numberOfStudent;
}

int getNumberOfStudents() {
	return 1;
}

void Course::printStudent() {
	for (int i = 0; i < getNumberOfStudents(); i++)  //������ ȫ�ֵ� ���� getNumberOfStudents(),Ч���� Course::getNumberOfStudents() ��ͬ��  
	{
		cout << student[i] << ",";
	}
}