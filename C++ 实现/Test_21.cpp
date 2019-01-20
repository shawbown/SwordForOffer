/*
��Ŀ��
	���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
����ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У�
��4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�

˼·��
	1.����һ������ջ����ջ��ѹ������ѹ�뵽����ջ��
	2.ѹ��һ��Ԫ�ؾ��뵯�����н��бȽϣ��������ջ��Ԫ���뵯��������Ⱦ͵���
	3.����жϸ���ջԪ���Ƿ���ȫ�����������ȫ�����˷���true�����򷵻�FALSE��
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        vector<int>::iterator iter1,iter2;
        
        iter2=popV.begin(); //iter2ָ��popV�ĵ�һ��Ԫ�ص�λ�� 
        if(pushV.size()==0)
            return false;
        for(iter1=pushV.begin();iter1!=pushV.end();iter1++)
        {
            stack1.push(*iter1);
       
            while(!stack1.empty()&&stack1.top()==(*iter2))
            {
                stack1.pop();
                iter2++;      
            }     
        }
        if(stack1.empty())
            return true;
        return false;
    }
private:
	stack<int> stack1;
};

//����ʵ�� 
vector<int> defArray(vector<int> p,int n){
	int a;
	for(int i=0;i<n;i++){
	cin>>a;
	p.push_back(a);
	}
	return p;
}
//��ӡ���� 
void printArray(vector<int> print){
	for(int i=0;i<print.size();i++){
		cout<<print[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	vector<int> pusharr,poparr;
	int n,a;
	cin>>n;
	pusharr=defArray(pusharr,n);
	poparr=defArray(poparr,n);

	Solution s;
	cout<<s.IsPopOrder(pusharr,poparr)<<endl;
	
	return 0;
	
} 
