/*
题目：
	 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
思路：
	1、先实现两个二叉树 
	2、判断二叉树是否为空，为空直接返回false
	3、如果二叉树不为空，进行递归比较 
*/

#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
 
//定义树的结构 
struct TreeNode { 
	int  val; 
	struct TreeNode *left; 
	struct TreeNode *right; 
	TreeNode(int x) : 
		val(x), left(NULL), right(NULL) { 
	} 
};
//定义根节点全局变量 
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

//按照前序遍历序列创建二叉树
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
