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
 /* ���������һ��λ�ÿ϶��Ǹ��ڵ�node��
��������ĸ��ڵ�λ�����м�p����p��ߵĿ϶���node�����������������飬
p�ұߵĿ϶���node������������������

��һ���棬��������ĵڶ���λ�õ�p��Ҳ��node�����������������飬
ʣ��p�ұߵľ���node��������������������
���ĸ������ҳ����������ҵݹ���ü���
*/
class Solution {
public:
     struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
     int s = vin.size();        //������еĳ���
	 if(s==0)            
	 return NULL;    
	     
	//�ֱ�洢�������е����������������е����������������е����������������е�������
	 vector<int> pre_left,pre_right,vin_left,vin_right;   
	  
	//�½�һ������㣬��������ֵ    
	 TreeNode* node = new TreeNode(pre[0]);     
	    
	//�½�һ����ǩindex����ʾpre[0]���������е�λ��
	 int index = 0;        
	 for(int i=0;i<s;i++){       
	//Find the root position in in      
		 if(vin[i]==pre[0]){                
		 	index = i;                
		 	break;            
		 }         
	 }  	      
	 for(int i=0;i<index;i++){         
	//�����������е���������ǰ�����е�������  
	  	pre_left.push_back(pre[i+1]);            
	  	vin_left.push_back(vin[i]);        
	  }        
	  for(int i=0;i<s-index-1;i++){            
	//�����������е���������ǰ�����е�������
	 	 pre_right.push_back(pre[i+index+1]);            
	 	 vin_right.push_back(vin[i+index+1]);        
	  }      
	     
	//ȡ��ǰ�������������ڵ���ߺ��ұߵ�����
	 //�ݹ飬�ٶ�������������в��裬��������������������������ֱ��Ҷ�ڵ�
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

