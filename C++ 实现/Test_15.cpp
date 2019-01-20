/*  
题目：
 输入一个链表，反转链表后，输出新链表的表头。

*/

#include<iostream>
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
    ListNode* ReverseList(ListNode* pHead) {

	if(pHead == NULL)
		return NULL;
	ListNode *pCurrent ,*pPre,*pNext;
	                              //一、指针的初始化阶段
	pPre = pHead;
	pCurrent = pPre->next ;
	while(pCurrent)               //二、反转单链表的核心代码
	{
		pNext = pCurrent->next ;   //1. 缓冲pCurrent后面的单链表
		pCurrent->next = pPre ;	   //2. 反转单链表
		pPre = pCurrent;           //3.让pPre指针后移
		pCurrent = pNext ;         //4. 让pCurrent指针后移
	}
					  			 //三、处理并返回头指针
	pHead->next = NULL;                //把原头结点的next域变成空指针
	pHead = pPre ;		           //把头结点指向最后一个结点产生新的头结点，也就是把原单链表的尾结点变成头结点
	return pHead;
	
    }
};

int main()
{
	struct ListNode *head,*p,*q,*f ;
	int n,a;
	unsigned int k;
	//确定输入多少个数n，确定输出倒数第k个数 
	cin>>n;
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
	f=s.ReverseList(head);	
	while(f!=NULL)
	{
		cout<<f->val<<" "; 
		f=f->next;
	}
	cout<<endl; 
	return 0;
}



