#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
        int first ,second ,result;
        //其中second值是预先设定为1 
        first = 0,second = 1,result =1;
        if(n < 2)
            return n;
        for(int i = 2; i < n; i++)
		{
            first = second;
            second = result;
            result = first + second;
        }
        return result;
    }
};
 int main()
 {
	int n;
	cin>>n;
	Solution s;
	cout << s.Fibonacci(n) << endl;	
	return 0;
 }



