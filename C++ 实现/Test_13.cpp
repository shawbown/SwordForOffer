/*
��Ŀ��
 ����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣�
 ���е�ż��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣 
 
˼·��
������������array2��array3��������array�������ȷ�������array3�У���ż����������array2��
Ȼ���ٽ�����array2�е�������array3��
�������array3������������array�� 
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
