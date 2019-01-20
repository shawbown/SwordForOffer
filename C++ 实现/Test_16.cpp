/*
题目：
	 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
思路：
	建立一个数组array，用来存储链表pHead2中的数值val，然后依次插入到链表pHead1中 ， 
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
//建立链表函数 DefineLinkList 
ListNode* DefineLinkList (ListNode* pHead,int n)
{
	struct ListNode *p,*q;
	int a;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		//申请空间 
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
	
	//确定链表 head1和head2分别输入n和k个数 
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

