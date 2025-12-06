#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 两数之和问题：在数组中找到两个数，使它们的和等于目标值，并返回这两个数的索引
class Solution {
public:
    // nums: 输入的整数数组
    // target: 目标和
    // 返回值: 满足条件的两个数的索引（如果没有则返回空向量）
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap; // 哈希表，存储数值及其索引
        numMap.reserve(nums.size());    // 预分配空间，提升插入效率
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i]; // 计算当前数的补数
            // 检查补数是否已经在哈希表中
            if (numMap.find(complement) != numMap.end()) {
                // 找到答案，返回补数和当前数的索引
                return { numMap[complement], i };
            }
            // 将当前数及其索引加入哈希表
            numMap[nums[i]] = i;
        }
        // 没有找到满足条件的两个数，返回空向量
        return {};
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 2, 7, 11, 15 }; // 输入数组
    int target = 9;                    // 目标和
    vector<int> result = solution.twoSum(nums, target); // 调用两数之和函数

    cout << "Indices: ";
    for (int index : result) {
        cout << index << " "; // 输出结果索引
    }
    cout << endl;
    return 0;
}