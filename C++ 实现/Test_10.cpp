
/*
��Ŀ��
���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ�
�ܹ��ж����ַ�����

������
С������2*1��С�����Ժ�ź��������ַ�ʽ����������n>2���ܷ�����F(n)�֣�
�����ŷ�ʱ�����һ�飬ʣ������F(n-1)�֣�
�����ŷ�ʱ����������飬ʣ������F(n-2)�֣�
��ˣ�F(n)=F(n-1)+F(n-2)
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
