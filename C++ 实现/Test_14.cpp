/*
题目：
	输入一个链表，输出该链表中倒数第k个结点。 
*/ 

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	//定义num，用来统计结点的数量 
    	int num=0;
        ListNode* p;
        
    	p=pListHead;   	
		while(p!=NULL)
        {
        	num++;
            p=p->next;
        }
        //重新让p指向 pListHead
    	p=pListHead;
    	//对判断结点是否在要找的范围内 
        if(k>num) 
			return NULL;
        else
        {
        	int i=num-k;
	         while(i--)
	        {
	            p=p->next;       
	        }
	        return p;
        }
    }
};

int main()
{
	struct ListNode *head,*p,*q,*f ;
	int n,a;
	unsigned int k;
	//确定输入多少个数n，确定输出倒数第k个数 
	cin>>n>>k;
	head=NULL;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		//申请空间 
		p=(struct ListNode*)malloc(sizeof(struct ListNode));
		p->val=a;
		p->next=NULL;
		if(head==NULL)
		{
			head=p;
		}
		else
		q->next=p;	
		q=p;
	}
	
	Solution s;
	f=s.FindKthToTail(head,k);
	
	cout<<f->val<<endl; 
	return 0;
}
