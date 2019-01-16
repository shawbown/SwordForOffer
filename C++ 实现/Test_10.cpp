
/*
题目：
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，
总共有多少种方法？

分析：
小矩形是2*1大小，可以横放和竖放两种方式，假设大矩形n>2，总方法记F(n)种，
当横着放时，则放一块，剩余则有F(n-1)种；
当竖着放时，则放了两块，剩余则有F(n-2)种；
因此：F(n)=F(n-1)+F(n-2)
*/

#include<iostream>
using namespace std;

class Solution {
public:
    int rectCover(int number) {
	if(number==0)
       		return 0;
       	else if(number==1)
       		return 1;
       	else if(number==2)
       		return 2;
       	else
       		return (rectCover(number-1)+rectCover(number-2));
    }
};
int main()
{
	int n;
	cin>>n;
	Solution s;
	cout<<s.rectCover(n)<<endl;
	
	return 0;
}
