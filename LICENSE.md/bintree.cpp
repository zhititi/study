/*(1050.string subtraction)Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and 
inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.
Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), the total number of 
nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the 
numbers in a line are separated by a space.
Output Specification:
For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in 
a line must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
7
2 3 1 5 7 6 4 postorder sequence
1 2 3 4 5 6 7 inorder sequence
Sample Output:
4 1 6 3 5 7 2*/
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 50;
struct node {
	int data;
	node* lchild;
	node* rchild;
};
int pre[maxn], in[maxn], post[maxn];//先序，中序，后序
int n;   //结点个数
//当前二叉树的后序序列区间为[postL,postR]，中序序列的区间为[inL,inR]
//create函数返回构建出的二叉树的根节点地址
node* create(int postL, int postR, int inL, int inR) {
	if (postL > postR)
		return NULL;

	node* root = new node;           //新建一个结点，用来存放当前二叉树的根节点
	root->data = post[postR];         //新结点的数据域为根节点的值
	int k;
	for (k = inL; k <= inR; k++) {
		if (in[k] == post[postR])     //在序列中找到in[k] == pre[L]的结点，k为该结点下标
			break;
	}

	int numleft = k - inL;           //左子树的结点个数
	//返回左子树的根结点地址，赋值给root的左指针
	root->lchild = create(postL, postL + numleft - 1, inL, k - 1);//这里postR变成了postL+numleft-1，inR变成了k-1
	//返回右子树根结点地址，赋值给root的右指针
	root->rchild = create(postL + numleft, postR - 1, k + 1, inR);
	return root;
}
int num = 0;//已输出的结点个数
void BFS(node* root)
{
	queue<node*> q;//注意队列里是存地址
	q.push(root);//将根结点地址入队
	while (!q.empty())
	{
		node* now = q.front();//取出队首元素
		q.pop();
		printf("%d", now->data);//访问队首元素
		num++;
		if (num < n) printf(" ");
		if (now->lchild != NULL) q.push(now->lchild);//左子树非空
		if (now->rchild != NULL) q.push(now->rchild);//右子树非空
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &post[i]);
	}//结点的值为1
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	node* root = create(0, n - 1, 0, n - 1); //建树
	BFS(root);       //层序遍历
	return 0;
}
