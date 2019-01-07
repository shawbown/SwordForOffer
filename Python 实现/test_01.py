"""
题目描述
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，
判断数组中是否含有该整数。
"""
"""
思路1:
矩阵是有序的，从左下角来看，向上数字递减，向右数字递增，
因此从***左下角开始查找***
当要查找数字比左下角数字大时,右移
当要查找数字比左下角数字小时,上移
思路：从左下角开始遍历，左下角开始，遇大右移，遇小上移，直到超过边界都没找到，得false。否则得true。
思路2：
从***右上角开始查找***
当要查找数字比右上角数字小时，左移
当要查找数字比右上角数字大时，下移
"""

class Solution:
    # array 二维列表
    def Find(self, target, array):
        row_count = len(array)
        col_count = len(array[0])
        if row_count == 0:    # 这里要考虑到二维数组为空的情况，如[[]]
            return False
        row, col = 0, col_count-1
        while row < row_count and col >= 0:
            if target == array[row][col]:
                return True
            elif target < array[row][col]:
                col -= 1
            else:
                row += 1
        return False

if __name__ == '__main__':
    '''测试用例'''
    target = 3
    array = [[1,2,8],[2,4,9],[3,6,10]]
    s = Solution()
    res = s.Find(target,array)
    print(res)
