/* 
��Ŀ��
����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
*/

#include<iostream>
using namespace std;

/* ��һ�� */
class Solution {
public:
	int NumberOf1(int n) {
        int index = 1;
        int number = 0;
        //ͨ�� �� �Ƚϣ�index��λ�Աȣ�number���м�¼���� 
        while(index!=0){
            if((n & index)!=0)
                number++;
            index = index << 1;
        }
        return number;
    }
};

/* �ڶ��� */
/* 
class Solution {
public:
	int NumberOf1(int n) {
		int number=0;
		char c[32];
		itoa(n,c,2);
		for(int i=0;i<32;i++)
		{
			if(c[i]=='1')
         		number++;	
		}
		return number;	
	}
};
*/

int main()
{
	int n;
	cin>>n;
	Solution s;
	cout<<s.NumberOf1(n)<<endl;
	
	return 0;
}
