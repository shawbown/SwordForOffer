/* 
题目：
 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
 
思路：
1、 exponent为正整数
	可以直接用循环 
2、 exponent为正零
	返回1 
3、exponent为负整数 
	循环之后，再用倒数 
*/
#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
    	double sum=1.0;
    	if(exponent>0){
    		for(int i=0;i<exponent;i++)
    			sum=sum*base;
    	}
    	else if(exponent==0)
    		return 1;
    	else
    	{
    		for(int i=0;i<abs(exponent);i++)
				sum=sum*base;
			sum=1/sum;	
    	}
    	return sum;
    }
};

int main()
{
	double base; 
	int exponent;
	cin>>base>>exponent;
	
	Solution s;
	cout<<s.Power( base,exponent)<<endl;
} 
