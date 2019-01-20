/*
��Ŀ��
	���������Ķ�����������任ΪԴ�������ľ���
˼·��
	 1�����ж϶��������ڵ��Ƿ�Ϊ�գ�
	 2���� �ж����������Ƿ��Ϊ�գ�
	 3�����������������Ľ�����
	 4���ݹ飻 
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
		//������������
		TreeNode *t=NULL;
		t=pRoot->left;	pRoot->left=pRoot->right;	pRoot->right=t;
		//�ݹ�
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

//����ǰ��������д���������
TreeNode * createBiTree(string s){
	root=NULL;
    int pos = -1;
    root=create(s,pos);
    return root;
}
//����ǰ����������� 
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
    //ԭ����������ǰ�������� 
	a=createBiTree(s);
	preOrder();
	
	Solution s1;
	s1.Mirror(a);
	//�޸ĺ�Ķ���������ǰ�������� 
	preOrder();
		
    return 0;
}
