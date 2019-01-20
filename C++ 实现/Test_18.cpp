/*
题目：
	操作给定的二叉树，将其变换为源二叉树的镜像。
思路：
	 1、先判断二叉树根节点是否为空；
	 2、再 判断左右子树是否均为空；
	 3、最后进行左右子树的交换；
	 4、递归； 
*/ 

#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
TreeNode *root=NULL;

class Solution {
public:
    void Mirror(TreeNode *pRoot) {
		if(pRoot==NULL)
			return ;
		if(pRoot->left==NULL&&pRoot->right==NULL)
			return ;
		//交换左右子树
		TreeNode *t=NULL;
		t=pRoot->left;	pRoot->left=pRoot->right;	pRoot->right=t;
		//递归
		if(pRoot!=NULL)
			 Mirror(pRoot->left);
		if(pRoot!=NULL)
			Mirror(pRoot->right);
    }
};

TreeNode* create(string &s,int &pos){
    ++pos;
    TreeNode* t;
    if((unsigned)pos>=s.size())
        return NULL;
    else{
        if(s[pos]=='#')
            t=NULL;
        else{
            t=(struct TreeNode*)malloc(sizeof(struct TreeNode));
            t->val=s[pos];
            t->left=create(s,pos);
            t->right=create(s,pos);
        }
        return t;
    }
}

//按照前序遍历序列创建二叉树
TreeNode * createBiTree(string s){
	root=NULL;
    int pos = -1;
    root=create(s,pos);
    return root;
}
//按照前序遍历二叉树 
void preOrder(){
	void pre_Order(TreeNode * t);
   	 pre_Order(root);
   	 cout<<endl;
}

void pre_Order(TreeNode * t){
    if(t!=NULL){
        cout<<(char)t->val<<' ';
        pre_Order(t->left);
        pre_Order(t->right);
    }
}

int main()
{
	TreeNode *a;
    string s;
    s="ABD##E#F##C##";
    //原二叉树按照前序遍历输出 
	a=createBiTree(s);
	preOrder();
	
	Solution s1;
	s1.Mirror(a);
	//修改后的二叉树按照前序遍历输出 
	preOrder();
		
    return 0;
}
