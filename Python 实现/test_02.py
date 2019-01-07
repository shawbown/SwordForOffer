"""
题目描述
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
"""
"""
解题思路
将序列依次判定是否为*空格*，若为空格则执行替换操作
"""

class Solution:
    # s 源字符串
    def replaceSpace(self, s):
        result = map(self.a, s)
        return ''.join(result)

    def a(self, x):
        if x == ' ':
            return '%20'
        return x


if __name__ == '__main__':
    s = Solution()
    res = s.replaceSpace('We Are Happy')
    print(res)

"""
结果：运行时间：34ms,占用内存：5728k
"""