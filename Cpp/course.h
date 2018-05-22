#include <string>  

using namespace std;

class Course
{
public:
	Course(const string& courseName, int Capacity);//初始化函数，定义对象的时候可以直接调用
	~Course();   //析构函数
	string getCoureName() const;
	void addStudent(const string& name);
	void dropStudent(const string& name);
	string* getStudent() const;
	int getNumberOfStudents() const;
	void printStudent();

private:           //私有的数据结构
	string courseName;
	string* student;
	int numberOfStudent;
	int Capacity;
};