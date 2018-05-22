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
#include "测试.h"
using namespace std;
static int a;//全局变量中的静态外部变量 只允许本文件使用（文件内有效）
extern int num;//extern在多文件的程序中声明外部变量。对一个已经定义的外部变量做说明，以扩展其作用域。

int all;//全局变量中的外部变量（其他文件可用）
//全局变量的有效范围从定义变量的位置到“本源文件”结束
//1.在程序的全部执行过程中都站存储单元 2.降低函数的通用性，可移植性 3.降低程序的清晰性
int cal(int a) {
	static int c = 1;//static声明静态局部变量（函数内有效），函数调用结束后c的值保留，内存空间不释放，下次调用时不会被static定义语句重新赋值。如果多次输入a=1则输出3 4 5 ...
	c++;
	return c + a;
}

int main() {
	int x, y;//局部变量只在本函数范围内有效，没有static声明，编译系统为他动态分配存储空间
	extern int m, n;//extern在一个文件里声明全局变量

	me luoxiao(21, 181, 6);
	me haoziqi;
	int sth = me::sth;//可以直接通过类名引用静态数据成员
	sth = luoxiao.sth;//也可以通过已定义的对象来访问
}
//全局变量局部变量重定义，以局部变量为准。

