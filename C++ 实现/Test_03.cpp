/* ����һ������������ֵ��β��ͷ��˳�򷵻�һ��ArrayList 

*˼·��
*�����������飬һ�����ڽ��������и��ڵ�����
*��һ������������յ�һ������������ �������صڶ������� 
*/

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

//����ListNode����ṹ 
struct ListNode {
    int val;		//����data 
    struct ListNode *next;
 };

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
		//������������array,array2 
        vector<int> array;
        vector<int> array2;
        //��������ָ��p��������array���鸳ֵ 
        ListNode* p;
        
        p=head;
        while(p!=NULL)
        {
        	//�����������ݸ�ֵ��array����
         	array.push_back(p->val);
         	p=p->next;
        }
        //������array�������������array2�� 
        for(int i=0;i<array.size();i++)
            {
                array2.push_back(array[array.size()-i-1]);
            }       
		return array2;
    }
};

int main()
{
	struct ListNode *head,*p,*q;
	int n,a;
	//�����нڵ�ĸ��� 
	cin>>n;
	head=NULL;
	for(int i=0;i<n;i++)
	{
		//������������ 
		cin>>a;
		//Ϊ����ָ��p���ٿռ� 
		p=(struct ListNode*)malloc(sizeof(struct ListNode));
		//�����ݴ浽��ǰ�ڵ�p�� 
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
	//������������array3�����ڽ���printListFromTailToHead()��������ֵ 
	vector<int> array3;	
	Solution printList;
	array3=printList.printListFromTailToHead(head);
	
	for(int i=0;i<array3.size();i++)
    {
        cout<<array3[i]<<" ";
    } 
    cout<<endl;
	return 0;
}
