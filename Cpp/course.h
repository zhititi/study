#include <string>  

using namespace std;

class Course
{
public:
	Course(const string& courseName, int Capacity);//��ʼ����������������ʱ�����ֱ�ӵ���
	~Course();   //��������
	string getCoureName() const;
	void addStudent(const string& name);
	void dropStudent(const string& name);
	string* getStudent() const;
	int getNumberOfStudents() const;
	void printStudent();

private:           //˽�е����ݽṹ
	string courseName;
	string* student;
	int numberOfStudent;
	int Capacity;
};