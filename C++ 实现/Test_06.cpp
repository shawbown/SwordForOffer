#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
	    //如果数组为空，返回0 
	     if (rotateArray.empty()) {
	            return 0;
	        }
   
        int low = 0;
        int high = rotateArray.size() - 1;
        int middle = 0;
        if (rotateArray.at(low) < rotateArray.at(high)) { //说明已经是非递减排序，直接返回第一个最小元素
            return rotateArray.at(low);
        }
   
        //二分查找
        while (low < high) {
        	//如果只有两个数，则返回后值，跳出循环 
            if (high - low == 1) {
                middle = high;
                break;
            }
   
            int middle = (low + high) / 2;
            //如果中间值大于等于low值，在最小值在middle之后 
            if (rotateArray.at(middle) >= rotateArray.at(low)) {
                low = middle;
            }
            //如果中间值小于等于low值，在最小值在middle之前 
            else if (rotateArray.at(middle) <= rotateArray.at(low)) {
                high = middle;
            }
        }          
        return rotateArray.at(middle);
    }
};

int main()
{
	int n,a;
	vector<int> array;
	//输入n个值给数字array 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		array.push_back(a);
	}
	Solution s;
	cout<<s.minNumberInRotateArray(array);
	
	return 0;
}
