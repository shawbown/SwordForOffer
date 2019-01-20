/*  
��Ŀ��
 ����һ��������ת��������������ı�ͷ��

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
	                              //һ��ָ��ĳ�ʼ���׶�
	pPre = pHead;
	pCurrent = pPre->next ;
	while(pCurrent)               //������ת������ĺ��Ĵ���
	{
		pNext = pCurrent->next ;   //1. ����pCurrent����ĵ�����
		pCurrent->next = pPre ;	   //2. ��ת������
		pPre = pCurrent;           //3.��pPreָ�����
		pCurrent = pNext ;         //4. ��pCurrentָ�����
	}
					  			 //������������ͷָ��
	pHead->next = NULL;                //��ԭͷ����next���ɿ�ָ��
	pHead = pPre ;		           //��ͷ���ָ�����һ���������µ�ͷ��㣬Ҳ���ǰ�ԭ�������β�����ͷ���
	return pHead;
	
    }
};

int main()
{
	struct ListNode *head,*p,*q,*f ;
	int n,a;
	unsigned int k;
	//ȷ��������ٸ���n��ȷ�����������k���� 
	cin>>n;
	head=NULL;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		//����ռ� 
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



