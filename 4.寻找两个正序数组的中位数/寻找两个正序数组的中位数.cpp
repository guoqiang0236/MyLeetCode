#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 确保 nums1 是较短的数组
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;

        // 在 nums1 上进行二分查找
        while (left <= right) {
            // i 是 nums1 的分割位置,左边有 i 个元素
            int i = (left + right) / 2;
            // j 是 nums2 的分割位置,保证左半部分元素总数 = (m+n+1)/2
            int j = (m + n + 1) / 2 - i;

            // 边界值处理
            int nums1LeftMax = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1RightMin = (i == m) ? INT_MAX : nums1[i];
            int nums2LeftMax = (j == 0) ? INT_MIN : nums2[j - 1];
            int nums2RightMin = (j == n) ? INT_MAX : nums2[j];

            // 检查分割是否正确
            if (nums1LeftMax <= nums2RightMin && nums2LeftMax <= nums1RightMin) {
                // 找到正确的分割
                if ((m + n) % 2 == 1) {
                    // 奇数个元素,中位数是左半部分的最大值
                    return max(nums1LeftMax, nums2LeftMax);
                }
                else {
                    // 偶数个元素,中位数是左半部分最大值和右半部分最小值的平均
                    return (max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin)) / 2.0;
                }
            }
            else if (nums1LeftMax > nums2RightMin) {
                // nums1 的分割位置太靠右,需要左移
                right = i - 1;
            }
            else {
                // nums1 的分割位置太靠左,需要右移
                left = i + 1;
            }
        }

        return 0.0;
    }
};

int main() {
    Solution solution;

    // 测试用例 1: 偶数个元素
    vector<int> nums1 = { 1, 3 };
    vector<int> nums2 = { 2 };
    cout << "测试用例 1:" << endl;
    cout << "nums1 = [1, 3], nums2 = [2]" << endl;
    cout << "中位数 = " << solution.findMedianSortedArrays(nums1, nums2) << endl;
    cout << "期望结果: 2" << endl << endl;

    // 测试用例 2: 奇数个元素
    vector<int> nums3 = { 1, 2 };
    vector<int> nums4 = { 3, 4 };
    cout << "测试用例 2:" << endl;
    cout << "nums1 = [1, 2], nums2 = [3, 4]" << endl;
    cout << "中位数 = " << solution.findMedianSortedArrays(nums3, nums4) << endl;
    cout << "期望结果: 2.5" << endl << endl;

    // 测试用例 3: 较复杂的情况
    vector<int> nums5 = { 1, 3, 8, 9, 15 };
    vector<int> nums6 = { 7, 11, 18, 19, 21, 25 };
    cout << "测试用例 3:" << endl;
    cout << "nums1 = [1, 3, 8, 9, 15], nums2 = [7, 11, 18, 19, 21, 25]" << endl;
    cout << "中位数 = " << solution.findMedianSortedArrays(nums5, nums6) << endl;
    cout << "期望结果: 10" << endl << endl;

    // 测试用例 4: 空数组
    vector<int> nums7 = {};
    vector<int> nums8 = { 1 };
    cout << "测试用例 4:" << endl;
    cout << "nums1 = [], nums2 = [1]" << endl;
    cout << "中位数 = " << solution.findMedianSortedArrays(nums7, nums8) << endl;
    cout << "期望结果: 1" << endl << endl;

    return 0;
}