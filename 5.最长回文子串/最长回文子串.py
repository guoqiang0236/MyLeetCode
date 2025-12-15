class Solution:
    def expandAroundCenter(self, s: str, left: int, right: int) -> tuple:
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return left + 1, right - 1  # 返回起始和结束位置
    def longestPalindrome(self, s: str) -> str:
        max_start, max_end = 0, 0
        for i in range(len(s)):
            # 奇数长度回文
            start1, end1 = self.expandAroundCenter(s, i, i)
            # 偶数长度回文
            start2, end2 = self.expandAroundCenter(s, i, i + 1)
            
            # 更新最长回文子串的位置
            if end1 - start1 > max_end - max_start:
                max_start, max_end = start1, end1
            if end2 - start2 > max_end - max_start:
                max_start, max_end = start2, end2
        return s[max_start:max_end + 1]
    