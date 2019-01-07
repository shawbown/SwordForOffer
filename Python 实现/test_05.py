"""
题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
"""
"""
解题思路
第一个栈stack_1临时保存插入的数据，当调用弹出函数时候，若stack_2不为空则直接弹出，
若为空，则把stack_1中的数据全部弹出放到stack_2中。
注：stack_2都是存放的旧的数据，弹出时一定符合队列的规律。
"""
class Solution:
    def __init__(self):
        self.stack_1 = []
        self.stack_2 = []

    def push(self,node):
        self.stack_1.append(node)

    def pop(self):
        if self.stack_2:
            return self.stack_2.pop()
        else:
            while self.stack_1:
                self.stack_2.append(self.stack_1.pop())
            return self.stack_2.pop()

if __name__ == '__main__':
    s = Solution()
    s.push(1)
    s.push(2)
    print(s.stack_1)
    s.pop()
    print(s.stack_2)
    print(s.stack_1)
