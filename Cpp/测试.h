#pragma once
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
using namespace std;
class me 
{
public:
	me(int a, int b, int c) { //构造函数来处理对象的初始化，构造函数必须与类名相同，在建立对象时自动执行，没有类型没有返回值，不能被用户调用，但可以带参数
		age = a;
		height = b;
	}
	me() {  //构造函数的重载
		age = 0;
		height = 0;
	}
	~me() {};  //析构函数
	inline void display() {  //在这里直接定义的叫内置成员函数，inline可以省略
		cout << name << endl;
	}
	inline int displayage();
	string findgirlfriend();   //公共成员函数是用户使用类的公用接口，或说类的对外接口
	static int sth;  //静态数据成员：各对象该数据的值时一样的。（等于把他跟成员函数放在了一起）
	static int count() {  //静态成员函数是类的一部分，而不是对象的一部分，用来访问静态成员函数，不能访问非静态成员函数。用 类名::函数名调用
		return sth;
	}
private:
	string name;
	int age;
	int height;
	string lover;
};

inline int me::displayage() {
	cout << age << endl;
	return 0;
}
//如果在类体外定义的内置函数，必须将类定义和成员函数的定义都放在一个头文件中（或者写在一个源文件中）
//内置函数在编译时将所调用函数的代码直接嵌入到主调函数中，这种函数称为内置函数（内嵌函数，内联函数），少了调用的时空开销，更方便

string me::findgirlfriend() {  //函数外定义成员函数，要加上类名me和成员限定符::
	cout << lover << endl;
}
//不同对象值是不同的，代码是相同的。成员函数无论在哪定义，都不占对象的存储空间