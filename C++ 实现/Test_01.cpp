
/*
��Ŀ����
��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������
ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ��������
�ж��������Ƿ��и�������

˼·�� 
����������ģ������½��������������ֵݼ����������ֵ�����
��˴����½ǿ�ʼ���ң���Ҫ�������ֱ����½����ִ�ʱ������
Ҫ�������ֱ����½�����Сʱ������
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
	vector<vector<int> >array(4,vector<int>(4));  //����һ��4*4�Ķ�ά����
	//������Ԫ�ظ�ֵ ȡֵΪ{1,2,3,4}��{2��3,6,7}��{3,4,7,8}��{5,6,9,10} 
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


