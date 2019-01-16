#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
	    //�������Ϊ�գ�����0 
	     if (rotateArray.empty()) {
	            return 0;
	        }
   
        int low = 0;
        int high = rotateArray.size() - 1;
        int middle = 0;
        if (rotateArray.at(low) < rotateArray.at(high)) { //˵���Ѿ��Ƿǵݼ�����ֱ�ӷ��ص�һ����СԪ��
            return rotateArray.at(low);
        }
   
        //���ֲ���
        while (low < high) {
        	//���ֻ�����������򷵻غ�ֵ������ѭ�� 
            if (high - low == 1) {
                middle = high;
                break;
            }
   
            int middle = (low + high) / 2;
            //����м�ֵ���ڵ���lowֵ������Сֵ��middle֮�� 
            if (rotateArray.at(middle) >= rotateArray.at(low)) {
                low = middle;
            }
            //����м�ֵС�ڵ���lowֵ������Сֵ��middle֮ǰ 
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
	//����n��ֵ������array 
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
