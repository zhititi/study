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
	me(int a, int b, int c) { //���캯�����������ĳ�ʼ�������캯��������������ͬ���ڽ�������ʱ�Զ�ִ�У�û������û�з���ֵ�����ܱ��û����ã������Դ�����
		age = a;
		height = b;
	}
	me() {  //���캯��������
		age = 0;
		height = 0;
	}
	~me() {};  //��������
	inline void display() {  //������ֱ�Ӷ���Ľ����ó�Ա������inline����ʡ��
		cout << name << endl;
	}
	inline int displayage();
	string findgirlfriend();   //������Ա�������û�ʹ����Ĺ��ýӿڣ���˵��Ķ���ӿ�
	static int sth;  //��̬���ݳ�Ա������������ݵ�ֵʱһ���ġ������ڰ�������Ա����������һ��
	static int count() {  //��̬��Ա���������һ���֣������Ƕ����һ���֣��������ʾ�̬��Ա���������ܷ��ʷǾ�̬��Ա�������� ����::����������
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
//����������ⶨ������ú��������뽫�ඨ��ͳ�Ա�����Ķ��嶼����һ��ͷ�ļ��У�����д��һ��Դ�ļ��У�
//���ú����ڱ���ʱ�������ú����Ĵ���ֱ��Ƕ�뵽���������У����ֺ�����Ϊ���ú�������Ƕ���������������������˵��õ�ʱ�տ�����������

string me::findgirlfriend() {  //�����ⶨ���Ա������Ҫ��������me�ͳ�Ա�޶���::
	cout << lover << endl;
}
//��ͬ����ֵ�ǲ�ͬ�ģ���������ͬ�ġ���Ա�����������Ķ��壬����ռ����Ĵ洢�ռ�