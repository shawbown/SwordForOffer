"""
题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
"""
"""
解题思路

"""
class TreeNode:
    def __init__(self, data, left=None, right= None):
        self.val = data
        self.left = left
        self.right = right

class Solution:
    # 根据前序和中序遍历重建二叉树
    def reConstructBinaryTree(self, pre, tin):
        if len(pre) == 0:
            return None
        if len(pre) == 1:
            return TreeNode(pre[0])
        root_val = pre[0]
        idx = tin.index(root_val)
        root = TreeNode(root_val)
        root.left = self.reConstructBinaryTree(pre[1:idx + 1], tin[:idx])
        root.right = self.reConstructBinaryTree(pre[idx + 1:], tin[idx + 1:])
        return root

if __name__ == '__main__':
    s = Solution()
    res = s.reConstructBinaryTree([1,2,4,7,3,5,6,8],[4,7,2,1,5,3,8,6])
    print(res)
