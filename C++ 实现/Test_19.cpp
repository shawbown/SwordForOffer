/*
��Ŀ��
	����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣����磬�����������4 X 4����
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 �����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

˼·:
	1�� �Ƚ����Ľ�λ�õı��� left,right,top,bottom������left��ʾ������У�right��ʾ���ұ���
		top��ʾ������һ�У�bottom��ʾ������һ�У�
	2�� �ȶ�left<right&&top<bottom���з�����
	3���ٷ�����ֻʣһ�С�����ֻʣһ�С�����ֻʣһ���������з������ɣ� 
	
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
			//������ 
			for(int i=left;i<=right;i++){
				array1.push_back(matrix[top][i]);
			}
			top++;
			//���ϵ��� 
			for(int i=top;i<=bottom;i++){
				array1.push_back(matrix[i][right]);
			}
			right--;
			//���ҵ���
			for(int i=right;i>=left;i--){
				array1.push_back(matrix[bottom][i]);
			} 
			bottom--;
			//���µ���
			for(int i=bottom;i>=top;i--){
				array1.push_back(matrix[i][left]);
			} 	
			left++;
		}
		//ֻʣ��һ�� 
		if(left<right&&top==bottom){
			for(int i=left;i<=right;i++){
				array1.push_back(matrix[top][i]);
			}	
		}
		//ֻʣ��һ�� 
		if(left==right&&top<bottom){
			for(int i=top;i<=bottom;i++){
				array1.push_back(matrix[i][left]);
			}	
		}
		//ֻʣ��һ����
		if(left==right&&top==bottom){
				array1.push_back(matrix[left][bottom]);	
		}
		return array1;
    }
};

int main()
{
	vector<int> a; 
	vector<vector<int> >array(4,vector<int>(4));  //����һ��4*4�Ķ�ά����
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
