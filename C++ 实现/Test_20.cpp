/*
��Ŀ��
	����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������
	
˼·��
	����һ�αȽϣ�ͨ������ջ���в����� 


*/ 

#include<iostream>
#include<stack>
#include<cstdlib>
using namespace std;

class Solution {
public:
	//�Ƚ������ν�ջ 
    void push(int value) {
        stack1.push(value);
    }
    void pop() {
     if(stack1.size() == 0)
            return;
        stack1.pop();
    }

    int top() {
        return stack1.top();
    }
    int min() {
        int min=stack1.top();
        while(!stack1.empty())
        {
        	if(min>stack1.top())
        		min=stack1.top();
        	stack2.push(stack1.top());
        	stack1.pop();
        }
        while(!stack2.empty()){
        	stack1.push(stack2.top());
        	stack2.pop();
        }
        return min;
    }
private:
	stack<int> stack1;
	stack<int> stack2;
};

int main()
{
	int n;
 	Solution s;
 	//��6��int����ջ 
 	for(int i=0;i<6;i++)
 	{
 		cin>>n;
 		s.push(n);
 	}
 	//����pop()����ģ������Ƚ��ȳ� 
	 	cout<<s.min()<<endl;	 
 	return 0;
}
