
/*
题目描述
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，
判断数组中是否含有该整数。

思路： 
矩阵是有序的，从左下角来看，向上数字递减，向右数字递增，
因此从左下角开始查找，当要查找数字比左下角数字大时。右移
要查找数字比左下角数字小时，上移
*/

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

class Solution{
	public:
		bool Find(int target,vector<vector<int> >array){
			int row=array.size();
			int col=array[0].size();
			int i,j;
			for(i=row-1,j=0;i>=0&&j<col;)
			{
				if(target<array[i][j])
		    	{
				    i--;
				    continue;
			    }
		    	else if(target>array[i][j])
		    	{
		    		j++;
		    		continue;
		    	}
		    	else
		    	    return true;
			}			
			return false;			
		}
};

int main()
{
	vector<vector<int> >array(4,vector<int>(4));  //定义一个4*4的二维数组
	//给数组元素赋值 取值为{1,2,3,4}，{2，3,6,7}，{3,4,7,8}，{5,6,9,10} 
	int n; 
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	{
		cin>>n;
		array[i][j]=n;
	} 
	Solution s; 
	cout<<s.Find(13,array);
	return 0;
}


