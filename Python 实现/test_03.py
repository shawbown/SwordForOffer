"""
题目描述
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
"""
"""
解题思路
讲链表的值放入一个list中，将list反向输出
注：重点学习将列表转换为ListNode。
"""
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:

    # 返回从尾部到头部的列表值序列，例如[1,2,3]
    def printListFromTailToHead(self, listNode):
        output = []
        while listNode is not None:
            output.append(listNode.val)
            listNode = listNode.next
        output.reverse()    # 采用reverse()函数,改函数直接改变原序列
        # output = list(reversed(output))    # reversed函数，该函数不改变原序列，会生成一个新的序列
        # output = output[::-1]    # 采用分片的方式
        return output

# 将列表转换成链表
def listToListNode(list_input):
    numbers = list_input
    dummyRoot = ListNode(0)
    ptr = dummyRoot
    for number in numbers:
        ptr.next = ListNode(number)    # 分别将列表中每个数转换成节点
        ptr = ptr.next
    ptr = dummyRoot.next
    return ptr

if __name__ == '__main__':
    chain = 123
    a = listToListNode(chain)
    s = Solution()
    res = s.printListFromTailToHead(a)
    print(res)