/* 
��Ŀ��
 ����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
 
˼·��
1�� exponentΪ������
	����ֱ����ѭ�� 
2�� exponentΪ����
	����1 
3��exponentΪ������ 
	ѭ��֮�����õ��� 
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
