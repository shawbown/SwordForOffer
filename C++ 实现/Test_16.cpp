/*
��Ŀ��
	 ���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������
˼·��
	����һ������array�������洢����pHead2�е���ֵval��Ȼ�����β��뵽����pHead1�� �� 
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
       vector<int> array;
       ListNode *p,*t;
        p=pHead2;
        while(p!=NULL)
        {
         	array.push_back(p->val);
            p=p->next;
        }
        p=pHead1;
        for(int i=0;i<array.size();i++){
        	while(p!=NULL){
        		if(p->next==NULL||p->next->val>array[i]){
        			t=(struct ListNode*)malloc(sizeof(struct ListNode));
        			t->val=array[i];
        			t->next=p->next;
        			p->next=t;
        			break;
        		}
        		p=p->next;
        	}
        }
        p=pHead1;
        return p;		 
    }
};
//���������� DefineLinkList 
ListNode* DefineLinkList (ListNode* pHead,int n)
{
	struct ListNode *p,*q;
	int a;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		//����ռ� 
		p=(struct ListNode*)malloc(sizeof(struct ListNode));
		p->val=a;
		p->next=NULL;
		if(pHead==NULL)
		{
			pHead=p;
		}
		else
		q->next=p;	
		q=p;
	}
	return pHead;
}

int main()
{
	struct ListNode *head1,*head2,*f;
	int n,k;
	
	//ȷ������ head1��head2�ֱ�����n��k���� 
	cin>>n>>k;
	
	head1=NULL; 	head2=NULL;
	head1=DefineLinkList (head1,n);
	head2=DefineLinkList (head2,k);
	
	Solution s;
	f=s.Merge(head1, head2);
	
	while(f!=NULL)
	{
		cout<<f->val<<" ";
		f=f->next;
	}
	cout<<endl;
	return 0;
}

