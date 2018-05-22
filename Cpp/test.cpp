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
//数据结构，树。不允许用全局变量。方法一：引用+output函数。方法二：sum1, sum2, sum法。方法三：flag法，找到了直接返回。
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

int num_1 = 0;                   //全局变量版本（不建议使用）
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

int countLeaves_2(node *root, int &num) {      //引用版本
	if (root == NULL) return num;
	if (root->lchild == NULL&&root->rchild == NULL) {
		num++;
		return num;
	}
	countLeaves_2(root->lchild, num);
	countLeaves_2(root->rchild, num);
	return num;
}

int countLeaves_3(node *root) {  //仅根结点版本
	int num1, num2, num = 0;
	if (root == NULL) return 0;
	if (root->lchild == NULL&&root->rchild == NULL) {
		num++;
		return num;  //在这里要有return num; 或者后面要有+= num1 + num2(自己想想为啥)
	}
	num1 = countLeaves_3(root->lchild);
	num2 = countLeaves_3(root->rchild);
	num = num1 + num2;
	return num;
}

int single(node *root) { //输出树中单子孙结点的个数
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

int minNode(node *root, int &min) {//找到最小值
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

void copy(node *root1, node *&root2) {  //复制一个二叉树，记得这里要加 &引用符
	if (root1 == NULL) {
		root2 = NULL;           //有了这句后面就不用加 lchild, rchild了
		return;
	}
	root2 = new node;
	root2->data = root1->data;
	//root2->lchild = root1->lchild;
	//root2->rchild = root1->rchild;
	copy(root1->lchild, root2->lchild);
	copy(root1->rchild, root2->rchild);
}

int numNode(node *root, int k, int h) {  //数树在高度k上结点个数
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

bool isBro(node *root, int a, int b) { //判断值为a, b的两结点是否为兄弟
	bool flag;
	if (root == NULL || root->lchild == NULL || root->rchild == NULL) return false;
	//因为用到了lchild和rchild的data，所以要确保这两个都不为空
	if ((root->lchild->data == a&&root->rchild->data == b) || (root->lchild->data == b&&root->rchild->data == a)) {
		return true;
	}
	flag = isBro(root->lchild, a, b);
	if (flag == true) return true;   //这句起到了能找到了停止的作用
	else return isBro(root->rchild, a, b);
}

void printNode(node *root) {        //求值为x的结点的所有子孙结点的先序遍历
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

void reverse(node *&root) {  //将二叉树的左右子树交换
	if (root == NULL) return;
	reverse(root->lchild);
	reverse(root->rchild);
	swap(root->lchild, root->rchild);
}

void reverse_1(node *root, node *&root1) {  //将二叉树的左右子树交换，要求不破坏原二叉树
	if (root == NULL) {
		root1 = NULL;
		return;
	}
	root1 = new node;              //构建一个新的二叉树时，记住这里要申请空间
	root1->data = root->data;
	reverse_1(root->lchild, root1->rchild);
	reverse_1(root->rchild, root1->lchild);
}

bool isSame(node *lroot,node *rroot) {     //判断二叉树两子树是否同构
	if (lroot == NULL&&rroot == NULL) {
		return true;
	}
	if (lroot == NULL||rroot == NULL) {
		return false;
	}
	return (isSame(lroot->lchild, rroot->lchild)&isSame(lroot->rchild, rroot->rchild));  //卧槽。。
}
bool isSame_1(node *root) {
	if (root == NULL)return true;          //这句不能少
	return isSame(root->lchild, root->rchild);
}

bool isComplete(node *root, int depth, int maxdepth) {    //判断二叉树是否为完全二叉树
	if (root == NULL) {
		if (depth == maxdepth) {
			return true;
		}
		return false;
	}
	return (isComplete(root->lchild, depth + 1, maxdepth)&isComplete(root->rchild, depth + 1, maxdepth));
}
int calDepth(node *root, int &depth) {   //用引用，实现了类似全局变量的效果
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