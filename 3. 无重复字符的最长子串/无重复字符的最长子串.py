class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char_index_map={}
        left=0
        max_length=0
        for right in range(len(s)):
            if s[right] in char_index_map and char_index_map[s[right]]>=left:
                left = char_index_map[s[right]]+1
          
            char_index_map[s[right]]=right
            max_length = max(max_length,right-left+1)

        return max_length
    
# 示例用法
if __name__ == "__main__":
    solution = Solution()
    test_string = "abcabcbb"
    result = solution.lengthOfLongestSubstring(test_string)
    print(f"The length of the longest substring without repeating characters in '{test_string}' is: {result}")