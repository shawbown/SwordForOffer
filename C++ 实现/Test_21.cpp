/*
题目：
	输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

思路：
	1.建立一个辅助栈，将栈的压入序列压入到辅助栈中
	2.压入一个元素就与弹出序列进行比较，如果辅助栈顶元素与弹出序列相等就弹出
	3.最后判断辅助栈元素是否被完全弹出，如果完全弹出了返回true，否则返回FALSE；
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        vector<int>::iterator iter1,iter2;
        
        iter2=popV.begin(); //iter2指向popV的第一个元素的位置 
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

//数组实现 
vector<int> defArray(vector<int> p,int n){
	int a;
	for(int i=0;i<n;i++){
	cin>>a;
	p.push_back(a);
	}
	return p;
}
//打印数组 
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
