/* 输入一个链表，按链表值从尾到头的顺序返回一个ArrayList 

*思路：
*建立两个数组，一个用于接收链表中各节点数据
*另一个用于逆向接收第一个数组中数据 ，并返回第二个数组 
*/

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

//建立ListNode链表结构 
struct ListNode {
    int val;		//链表data 
    struct ListNode *next;
 };

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
		//建立整型数组array,array2 
        vector<int> array;
        vector<int> array2;
        //建立链表指针p，用于向array数组赋值 
        ListNode* p;
        
        p=head;
        while(p!=NULL)
        {
        	//将链表中数据赋值给array数组
         	array.push_back(p->val);
         	p=p->next;
        }
        //将数组array中数据逆向加入array2中 
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
	//链表中节点的个数 
	cin>>n;
	head=NULL;
	for(int i=0;i<n;i++)
	{
		//输入链表数据 
		cin>>a;
		//为链表指针p开辟空间 
		p=(struct ListNode*)malloc(sizeof(struct ListNode));
		//将数据存到当前节点p中 
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
	//创建整型数组array3，用于接收printListFromTailToHead()函数返回值 
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
