/*
题目：
	定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
	
思路：
	遍历一次比较，通过辅助栈进行操作。 


*/ 

#include<iostream>
#include<stack>
#include<cstdlib>
using namespace std;

class Solution {
public:
	//先将数依次进栈 
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
 	//将6个int数进栈 
 	for(int i=0;i<6;i++)
 	{
 		cin>>n;
 		s.push(n);
 	}
 	//调用pop()函数模拟队列先进先出 
	 	cout<<s.min()<<endl;	 
 	return 0;
}
