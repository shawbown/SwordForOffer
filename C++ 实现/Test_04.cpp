#include <iostream>
#include <vector>
using namespace std;

// Definition for binary tree
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 /* 先序遍历第一个位置肯定是根节点node，
中序遍历的根节点位置在中间p，在p左边的肯定是node的左子树的中序数组，
p右边的肯定是node的右子树的中序数组

另一方面，先序遍历的第二个位置到p，也是node左子树的先序子数组，
剩下p右边的就是node的右子树的先序子数组
把四个数组找出来，分左右递归调用即可
*/
class Solution {
public:
     struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
     int s = vin.size();        //获得序列的长度
	 if(s==0)            
	 return NULL;    
	     
	//分别存储先序序列的左子树，先序序列的右子树，中序序列的左子树，中序序列的右子树
	 vector<int> pre_left,pre_right,vin_left,vin_right;   
	  
	//新建一个树结点，并传入结点值    
	 TreeNode* node = new TreeNode(pre[0]);     
	    
	//新建一个标签index，表示pre[0]在中序序列的位置
	 int index = 0;        
	 for(int i=0;i<s;i++){       
	//Find the root position in in      
		 if(vin[i]==pre[0]){                
		 	index = i;                
		 	break;            
		 }         
	 }  	      
	 for(int i=0;i<index;i++){         
	//建立中序序列的左子树和前序序列的左子树  
	  	pre_left.push_back(pre[i+1]);            
	  	vin_left.push_back(vin[i]);        
	  }        
	  for(int i=0;i<s-index-1;i++){            
	//建立中序序列的右子树和前序序列的右子树
	 	 pre_right.push_back(pre[i+index+1]);            
	 	 vin_right.push_back(vin[i+index+1]);        
	  }      
	     
	//取出前序和中序遍历根节点左边和右边的子树
	 //递归，再对其进行上述所有步骤，即再区分子树的左、右子子数，直到叶节点
	   node->left = reConstructBinaryTree(pre_left,vin_left);        
	   node->right = reConstructBinaryTree(pre_right,vin_right);        
	   return node;
	    }
};

int main()
{
	struct TreeNode *Node,*Node_left,*Node_right;
	int n,length = 8;
	vector< int > preorder(length),inorder(length);
	
	for(int j=0;j<length;j++)
	{
		cin>>n;
		preorder[j]=n;
	} 
	for(int i=0;i<length;i++)
	{
		cin>>n;
		inorder[i]=n;
	} 
	Solution S;
	Node = S.reConstructBinaryTree(preorder,inorder);
	cout<<Node->val<<" "<<Node->left->val<<" "<<Node->right->val<<endl;	
	return 0;
}

