#include<iostream>
#include<stack>
using namespace std;
 
class Solution
{
public:
	//�Ƚ������ν�ջ 
    void push(int node) {
        stack1.push(node);
    }
    int pop() {
    	//�ٽ�ջstack1�е������ε��뵽ջ stack2�� 
        while(!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        //����ջ2ջ������a����pop()�ķ���ֵ 
        int a=stack2.top();
        stack2.pop();
        //�ٽ�ջ2�������ε��뵽ջ1�� 
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
 	//��6��int����ջ 
 	for(int i=0;i<6;i++)
 	{
 		cin>>n;
 		s.push(n);
 	}
 	//����pop()����ģ������Ƚ��ȳ� 
 	for(int i=0;i<6;i++)
	 {
	 	cout<<s.pop()<<endl;
	 }		 
 	return 0;
}
