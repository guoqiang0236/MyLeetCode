#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    // 从中心向两边扩展，找到回文子串的边界
    pair<int, int> expandAroundCenter(const string& s, int left, int right) {
        // 只要左右字符相等，就继续扩展
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        // 返回回文子串的起始和结束位置
        return { left + 1, right - 1 };
    }
 
    // 找到字符串中最长的回文子串
    string longestPalindrome(string s) {
        int maxStart = 0;  // 最长回文子串的起始位置
        int maxEnd = 0;    // 最长回文子串的结束位置

        // 遍历每个位置作为回文中心
        for (int i = 0; i < s.size(); i++) {
            // 情况1：奇数长度回文，如 "aba"
            pair<int, int> odd = expandAroundCenter(s, i, i);
            // 情况2：偶数长度回文，如 "abba"
            pair<int, int> even = expandAroundCenter(s, i, i + 1);

            // 检查奇数长度回文是否更长
            if (odd.second - odd.first > maxEnd - maxStart) {
                maxStart = odd.first;
                maxEnd = odd.second;
            }

            // 检查偶数长度回文是否更长
            if (even.second - even.first > maxEnd - maxStart) {
                maxStart = even.first;
                maxEnd = even.second;
            }
        }

        // 返回最长回文子串
        return s.substr(maxStart, maxEnd - maxStart + 1);
    }
};

int main() {
    Solution sol;
    string input;

    cout << "请输入字符串: ";
    cin >> input;

    string answer = sol.longestPalindrome(input);
    cout << "最长回文子串: " << answer << endl;

    return 0;
}