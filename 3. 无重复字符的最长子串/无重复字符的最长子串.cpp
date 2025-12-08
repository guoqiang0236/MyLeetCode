#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char currentChar = s[right];

            // 如果字符已存在且在当前窗口内，移动左指针
            if (charIndex.find(currentChar) != charIndex.end() && charIndex[currentChar] >= left) {
                left = charIndex[currentChar] + 1;
            }

            // 更新字符的最新位置
            charIndex[currentChar] = right;

            // 更新最大长度
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution solution;

    // 测试用例
    cout << "测试用例 1:" << endl;
    cout << "输入: s = \"abcabcbb\"" << endl;
    cout << "输出: " << solution.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << "预期: 3" << endl << endl;

    cout << "测试用例 2:" << endl;
    cout << "输入: s = \"bbbbb\"" << endl;
    cout << "输出: " << solution.lengthOfLongestSubstring("bbbbb") << endl;
    cout << "预期: 1" << endl << endl;

    cout << "测试用例 3:" << endl;
    cout << "输入: s = \"pwwkew\"" << endl;
    cout << "输出: " << solution.lengthOfLongestSubstring("pwwkew") << endl;
    cout << "预期: 3" << endl << endl;

    cout << "测试用例 4:" << endl;
    cout << "输入: s = \"\"" << endl;
    cout << "输出: " << solution.lengthOfLongestSubstring("") << endl;
    cout << "预期: 0" << endl;

    return 0;
}