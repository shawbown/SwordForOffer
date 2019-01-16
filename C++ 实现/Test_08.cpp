#include<iostream>
using namespace std;

/* 第一种 */
class Solution {
public:
    int jumpFloor(int number) {
    	int n1=1,n2=1,n3=0;
    	
    	if(number<=1)
    		return 1;
    	else
    	{
    		for(int i=1;i<number;i++){
    			n3=n2+n1;
    			n1=n2;
    			n2=n3;
    		}
    		return n3;
    	}
    }
};

/* 第二种 */
class Solution2 {
public:
    int jumpFloor(int number) {
    	if(number==0)
       		return 0;
       	else if(number==1)
       		return 1;
       	else if(number==2)
       		return 2;
       	else
       		return (jumpFloor(number-1)+jumpFloor(number-2));
    }
};
int main()
{
	int n;
	cin>>n;
	Solution s;
	cout<<s.jumpFloor(n)<<endl;
	
	Solution2 s2;
	cout<<s2.jumpFloor(n)<<endl;
	
	return 0;
}
