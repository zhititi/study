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
#include "����.h"
using namespace std;
static int a;//ȫ�ֱ����еľ�̬�ⲿ���� ֻ�����ļ�ʹ�ã��ļ�����Ч��
extern int num;//extern�ڶ��ļ��ĳ����������ⲿ��������һ���Ѿ�������ⲿ������˵��������չ��������

int all;//ȫ�ֱ����е��ⲿ�����������ļ����ã�
//ȫ�ֱ�������Ч��Χ�Ӷ��������λ�õ�����Դ�ļ�������
//1.�ڳ����ȫ��ִ�й����ж�վ�洢��Ԫ 2.���ͺ�����ͨ���ԣ�����ֲ�� 3.���ͳ����������
int cal(int a) {
	static int c = 1;//static������̬�ֲ���������������Ч�����������ý�����c��ֵ�������ڴ�ռ䲻�ͷţ��´ε���ʱ���ᱻstatic����������¸�ֵ������������a=1�����3 4 5 ...
	c++;
	return c + a;
}

int main() {
	int x, y;//�ֲ�����ֻ�ڱ�������Χ����Ч��û��static����������ϵͳΪ����̬����洢�ռ�
	extern int m, n;//extern��һ���ļ�������ȫ�ֱ���

	me luoxiao(21, 181, 6);
	me haoziqi;
	int sth = me::sth;//����ֱ��ͨ���������þ�̬���ݳ�Ա
	sth = luoxiao.sth;//Ҳ����ͨ���Ѷ���Ķ���������
}
//ȫ�ֱ����ֲ������ض��壬�Ծֲ�����Ϊ׼��

