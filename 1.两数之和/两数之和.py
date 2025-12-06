from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        """
        找到数组中两个数之和等于目标值的索引
        使用哈希表优化查找，时间复杂度 O(n)
        """
        # 创建字典存储 {数值: 索引}
        num_to_index = {}
        
        # 遍历数组
        for index, num in enumerate(nums):
            # 计算需要找的另一个数
            complement = target - num
            
            # 如果另一个数已经在字典中，返回两个索引
            if complement in num_to_index:
                return [num_to_index[complement], index]
            
            # 将当前数字及其索引存入字典
            num_to_index[num] = index
        
        # 如果没有找到（题目保证有解，一般不会执行到这里）
        return []
        


if __name__ == "__main__":
    solution = Solution()
    nums = [2, 7, 11, 15]
    target = 9
    result = solution.twoSum(nums, target)
    print(f"输入: nums = {nums}, target = {target}")
    print(f"输出: {result}")
    