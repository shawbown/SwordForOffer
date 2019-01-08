class Solution:
    def MinInOrder(self, rotateArray, left, right):
        res = rotateArray[left]
        for i in range(left, right + 1):
            if res > rotateArray[i]:
                res = rotateArray[i]
        return res

    def minNumberInRotateArray(self, rotateArray):
        # write code here
        lenArr = len(rotateArray)
        left, right = 0, lenArr - 1
        while left <= right:
            if right - left == 1:
                return rotateArray[right]
            mid = (left + right) // 2
            if rotateArray[left] == rotateArray[mid] \
                    and rotateArray[mid] == rotateArray[right]:
                return self.MinInOrder(rotateArray, left, right)
            if rotateArray[mid] >= rotateArray[left]:
                left = mid
            elif rotateArray[mid] <= rotateArray[right]:
                right = mid
        return rotateArray[right]


if __name__ == '__main__':
    s = Solution()
    res = s.minNumberInRotateArray([3,1,5,4,2])
    print(res)