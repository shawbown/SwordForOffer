/*
��Ŀ��
	����һ����������������е�����k����㡣 
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
    	//����num������ͳ�ƽ������� 
    	int num=0;
        ListNode* p;
        
    	p=pListHead;   	
		while(p!=NULL)
        {
        	num++;
            p=p->next;
        }
        //������pָ�� pListHead
    	p=pListHead;
    	//���жϽ���Ƿ���Ҫ�ҵķ�Χ�� 
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
	//ȷ��������ٸ���n��ȷ�����������k���� 
	cin>>n>>k;
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
	f=s.FindKthToTail(head,k);
	
	cout<<f->val<<endl; 
	return 0;
}
