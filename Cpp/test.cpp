#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;
//���ݽṹ��������������ȫ�ֱ���������һ������+output��������������sum1, sum2, sum������������flag�����ҵ���ֱ�ӷ��ء�
//
struct node {
	int data;
	node *lchild, *rchild;
};
int post[10010], in[10010];
int n;
node *create(int postl, int postr, int inl, int inr) {
	if (postl > postr) return NULL;
	int k;
	for (k = 0; k < n; k++) {
		if (post[postr] == in[k]) break;
	}
	int numleft = k - inl;
	node *now = new node;
	now->data = post[postr];
	now->lchild = create(postl, postl + numleft - 1, inl, k - 1);
	now->rchild = create(postl + numleft, postr - 1, k + 1, inr);
	return now;
}

int num_1 = 0;                   //ȫ�ֱ����汾��������ʹ�ã�
int countLeaves_1(node *root) {
	if (root == NULL) return num_1;
	if (root->lchild == NULL&&root->rchild == NULL) {
		num_1++;
		return num_1;
	}
	countLeaves_1(root->lchild);
	countLeaves_1(root->rchild);
	return num_1;
}

int countLeaves_2(node *root, int &num) {      //���ð汾
	if (root == NULL) return num;
	if (root->lchild == NULL&&root->rchild == NULL) {
		num++;
		return num;
	}
	countLeaves_2(root->lchild, num);
	countLeaves_2(root->rchild, num);
	return num;
}

int countLeaves_3(node *root) {  //�������汾
	int num1, num2, num = 0;
	if (root == NULL) return 0;
	if (root->lchild == NULL&&root->rchild == NULL) {
		num++;
		return num;  //������Ҫ��return num; ���ߺ���Ҫ��+= num1 + num2(�Լ�����Ϊɶ)
	}
	num1 = countLeaves_3(root->lchild);
	num2 = countLeaves_3(root->rchild);
	num = num1 + num2;
	return num;
}

int single(node *root) { //������е�������ĸ���
	int num1, num2, num = 0;
	if (root == NULL) return 0;
	if ((root->rchild == NULL&&root->lchild != NULL) || (root->rchild != NULL&&root->lchild == NULL)) {
		num++; 
	}
	num1 = single(root->lchild);
	num2 = single(root->rchild);
	num += num1 + num2;
	return num;
}

int minNode(node *root, int &min) {//�ҵ���Сֵ
	if (root == NULL) return 0;
	if (root->data < min) min = root->data;
	minNode(root->lchild, min);
	minNode(root->rchild, min);
	return min;
}
int findMinNode(node *root) {
	int min = 100000;
	int ans = minNode(root, min);
	return ans;
}

void copy(node *root1, node *&root2) {  //����һ�����������ǵ�����Ҫ�� &���÷�
	if (root1 == NULL) {
		root2 = NULL;           //����������Ͳ��ü� lchild, rchild��
		return;
	}
	root2 = new node;
	root2->data = root1->data;
	//root2->lchild = root1->lchild;
	//root2->rchild = root1->rchild;
	copy(root1->lchild, root2->lchild);
	copy(root1->rchild, root2->rchild);
}

int numNode(node *root, int k, int h) {  //�����ڸ߶�k�Ͻ�����
	int num1, num2, num = 0;
	if (root == NULL) return 0;
	if (h == k) {
		num++;
	}
	num1 = numNode(root->lchild, k, h + 1);
	num2 = numNode(root->rchild, k, h + 1);
	num += num1 + num2;
	return num;
}
int disNumNode(node *root, int k) {
	int temp = numNode(root, k, 1);
	return temp;
}

bool isBro(node *root, int a, int b) { //�ж�ֵΪa, b��������Ƿ�Ϊ�ֵ�
	bool flag;
	if (root == NULL || root->lchild == NULL || root->rchild == NULL) return false;
	//��Ϊ�õ���lchild��rchild��data������Ҫȷ������������Ϊ��
	if ((root->lchild->data == a&&root->rchild->data == b) || (root->lchild->data == b&&root->rchild->data == a)) {
		return true;
	}
	flag = isBro(root->lchild, a, b);
	if (flag == true) return true;   //����������ҵ���ֹͣ������
	else return isBro(root->rchild, a, b);
}

void printNode(node *root) {        //��ֵΪx�Ľ���������������������
	if (root == NULL)return;

	printf("%d ", root->data);
	printNode(root->lchild);
	printNode(root->rchild);
}
bool sunPrint(node *root, int x) {
	bool flag;
	if (root == NULL)return false;
	if (root->data == x) {
		printNode(root->lchild);
		printNode(root->rchild);
		return true;
	}
	flag = sunPrint(root->lchild, x);
	if (flag == true)return true;
	else return sunPrint(root->rchild, x);
}

void reverse(node *&root) {  //����������������������
	if (root == NULL) return;
	reverse(root->lchild);
	reverse(root->rchild);
	swap(root->lchild, root->rchild);
}

void reverse_1(node *root, node *&root1) {  //������������������������Ҫ���ƻ�ԭ������
	if (root == NULL) {
		root1 = NULL;
		return;
	}
	root1 = new node;              //����һ���µĶ�����ʱ����ס����Ҫ����ռ�
	root1->data = root->data;
	reverse_1(root->lchild, root1->rchild);
	reverse_1(root->rchild, root1->lchild);
}

bool isSame(node *lroot,node *rroot) {     //�ж϶������������Ƿ�ͬ��
	if (lroot == NULL&&rroot == NULL) {
		return true;
	}
	if (lroot == NULL||rroot == NULL) {
		return false;
	}
	return (isSame(lroot->lchild, rroot->lchild)&isSame(lroot->rchild, rroot->rchild));  //�Բۡ���
}
bool isSame_1(node *root) {
	if (root == NULL)return true;          //��䲻����
	return isSame(root->lchild, root->rchild);
}

bool isComplete(node *root, int depth, int maxdepth) {    //�ж϶������Ƿ�Ϊ��ȫ������
	if (root == NULL) {
		if (depth == maxdepth) {
			return true;
		}
		return false;
	}
	return (isComplete(root->lchild, depth + 1, maxdepth)&isComplete(root->rchild, depth + 1, maxdepth));
}
int calDepth(node *root, int &depth) {   //�����ã�ʵ��������ȫ�ֱ�����Ч��
	if (root == NULL) return depth;
	depth++;
	calDepth(root->lchild, depth);
	return depth;
}
bool isCompleteJudge(node *root) {
	int maxdepth = 0;
	calDepth(root, maxdepth);
	return isComplete(root, 0, maxdepth);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &post[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	node *root = create(0, n - 1, 0, n - 1);
	bool flag = isCompleteJudge(root);
	cout << flag;
}

/*
8
2 10 3 4 7 8 5 6
10 2 3 6 4 5 7 8
*/