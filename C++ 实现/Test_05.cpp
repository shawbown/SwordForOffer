#include<iostream>
#include<stack>
using namespace std;
 
class Solution
{
public:
	//先将数依次进栈 
    void push(int node) {
        stack1.push(node);
    }
    int pop() {
    	//再将栈stack1中的数依次弹入到栈 stack2中 
        while(!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        //返回栈2栈顶数给a，做pop()的返回值 
        int a=stack2.top();
        stack2.pop();
        //再将栈2的数依次弹入到栈1中 
         while(!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }   
        return a;
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
 	for(int i=0;i<6;i++)
	 {
	 	cout<<s.pop()<<endl;
	 }		 
 	return 0;
}
