/*
题目：
	输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵：
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

思路:
	1、 先建立四角位置的变量 left,right,top,bottom，其中left表示最左边列，right表示最右边列
		top表示最上面一行，bottom表示最下面一行；
	2、 先对left<right&&top<bottom进行分析；
	3、再分析“只剩一行”、“只剩一列”、“只剩一个数”进行分析即可； 
	
*/
#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
    	vector<int> array1;
    	int left=0,right,top=0,bottom;
    	right=matrix[0].size()-1;
    	bottom=matrix.size()-1;
    	
		while(left<right&&top<bottom){
			//从左到右 
			for(int i=left;i<=right;i++){
				array1.push_back(matrix[top][i]);
			}
			top++;
			//从上到下 
			for(int i=top;i<=bottom;i++){
				array1.push_back(matrix[i][right]);
			}
			right--;
			//从右到左
			for(int i=right;i>=left;i--){
				array1.push_back(matrix[bottom][i]);
			} 
			bottom--;
			//从下到上
			for(int i=bottom;i>=top;i--){
				array1.push_back(matrix[i][left]);
			} 	
			left++;
		}
		//只剩下一行 
		if(left<right&&top==bottom){
			for(int i=left;i<=right;i++){
				array1.push_back(matrix[top][i]);
			}	
		}
		//只剩下一列 
		if(left==right&&top<bottom){
			for(int i=top;i<=bottom;i++){
				array1.push_back(matrix[i][left]);
			}	
		}
		//只剩下一个数
		if(left==right&&top==bottom){
				array1.push_back(matrix[left][bottom]);	
		}
		return array1;
    }
};

int main()
{
	vector<int> a; 
	vector<vector<int> >array(4,vector<int>(4));  //定义一个4*4的二维数组
	int n; 
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	{
		cin>>n;
		array[i][j]=n;
	} 
	Solution s; 
	a=s.printMatrix(array);
	for(int i=0;i<a.size();i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
