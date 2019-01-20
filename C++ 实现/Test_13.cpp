/*
题目：
 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
 所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。 
 
思路：
建立两个数组array2和array3，将数组array中奇数先放入数组array3中，将偶数放入数组array2中
然后再将数组array2中的数放入array3中
最后将数组array3中数放入数组array中 
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> array2;
        vector<int> array3;
        for(int i=0;i<array.size();i++)
        {
        	if(array[i]%2==1) 
        		array3.push_back(array[i]);
        	else
        		array2.push_back(array[i]);
        }
        for(int i=0;i<array2.size();i++){
        	array3.push_back(array2[i]);
        }
        for(int i=0;i<array.size();i++){
        	array[i]=array3[i];
        }
    }
};

int main()
{
	vector<int> array1;
	int n,a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		array1.push_back(a);
	} 
	Solution s;
	s.reOrderArray(array1);
    for(int i=0;i<array1.size();i++){
		cout<<array1[i]<<" ";
	}
	
	cout<<endl;
	
	return 0;

} 
