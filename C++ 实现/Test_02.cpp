#include <iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
//lengthΪϵͳ�涨�ַ����������󳤶ȣ��̶�Ϊһ������

class Solution {
public:
    void replaceSpace(char *str, int length){
        int blankNumber = 0;//�ո������
        int oldstringLen;//��¼ԭ�ַ����ĳ���
        
        //���ȱ���ԭ�ַ������ҳ��ַ����ĳ����Լ��ո�������
        for (oldstringLen = 0; str[oldstringLen] != '\0'; oldstringLen++)
		{
            if (str[oldstringLen] == ' ')
            	blankNumber++;
        }

        //����ԭ�ַ����ĳ��ȺͿո���������ǿ������������ַ����ĳ���
        int newstringLen = oldstringLen + blankNumber*2;//���ַ����ĳ���
       
	    // �߽��飺�ж��ַ������Ƿ�Խ�磬���Խ�磬���ж��滻 
        if (newstringLen>length)
            return;
            
        //���к���Ҫ����Ϊԭ�ַ������һ���ַ�Ϊ'\0'
        str[newstringLen] = '\0';
		
        //��������ָ��point1��point2�ֱ�ָ��ԭ�ַ��������ַ�����ĩβλ��
        //��Ϊ'\0'�Ѿ��ֹ��ӵ�����´������һ���ַ������Լ�1
        int point1 = oldstringLen - 1, point2 = newstringLen - 1;

        while (point1 >= 0 && point2>point1){//��ָ����ͬʱ������ѭ��
            if (str[point1] == ' '){//���point1ָ��Ϊ�ո���ô��point2��ʼ��ֵ��02%��
                str[point2--] = '0';
                str[point2--] = '2';
                str[point2--] = '%';

            }
            else    //���point1ָ�����ݲ�Ϊ�ո���ô�����ݸ�ֵ��point2ָ���λ��
                str[point2--] = str[point1];
                
            //������if����else��Ҫ��point1ǰ��,Ϊ����һ�ε�ִ��    
            point1--;
        }
    }
};

    
int main()
{
	char arr1[40]= "we are happy.";
	//lΪarr1����ռ�ܿռ���ֽ���  
	int l;
	l=sizeof(arr1);
	Solution S;
	S.replaceSpace(arr1,l);
	cout<<arr1<<endl;
	return 0;
} 

