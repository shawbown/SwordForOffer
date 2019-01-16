#include<iostream>
using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
		if(number<=1)
			return 1;
		else
			return jumpFloorII(number-1)*2;
    }
};


int main()
{
	int n;
	cin>>n;
	Solution s;
	cout<<s.jumpFloorII(n)<<endl;
	
	return 0;
}
