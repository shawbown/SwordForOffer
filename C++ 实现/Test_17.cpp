/*
��Ŀ��
	 �������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
˼·��
	1����ʵ������������ 
	2���ж϶������Ƿ�Ϊ�գ�Ϊ��ֱ�ӷ���false
	3�������������Ϊ�գ����еݹ�Ƚ� 
*/

#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
 
//�������Ľṹ 
struct TreeNode { 
	int  val; 
	struct TreeNode *left; 
	struct TreeNode *right; 
	TreeNode(int x) : 
		val(x), left(NULL), right(NULL) { 
	} 
};
//������ڵ�ȫ�ֱ��� 
TreeNode *root=NULL;

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(!pRoot1)
            return false;
        if(!pRoot2)
            return false;
        return ( dfs(pRoot1,pRoot2)) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
private:
    bool dfs(TreeNode * r1, TreeNode * r2){
        if(!r2)
            return true;
        if(!r1)
            return false;
        if(r1->val != r2->val)
            return false;
        return dfs(r1->left, r2->left) && dfs(r1->right, r2->right);
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
TreeNode* createBiTree(string s){
	root=NULL;
    int pos = -1;
    root=create(s,pos);
    return root;
}

int main()
{
	TreeNode *a,*b;

    string s1,s2;
    s1="ABD##E#F##C##";
    s2="BD##E#F##";
    a=createBiTree(s1);  
    b=createBiTree(s2);

    Solution s;
    cout<<s.HasSubtree(a,b)<<endl;
    return 0;
}
