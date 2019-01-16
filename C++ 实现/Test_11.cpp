/* 
题目：
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/

#include<iostream>
using namespace std;

/* 第一种 */
class Solution {
public:
	int NumberOf1(int n) {
        int index = 1;
        int number = 0;
        //通过 与 比较，index移位对比，number进行记录数据 
        while(index!=0){
            if((n & index)!=0)
                number++;
            index = index << 1;
        }
        return number;
    }
};

/* 第二种 */
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
