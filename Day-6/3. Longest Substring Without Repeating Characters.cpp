/*
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int i = 0, j = 0, n = s.size(), ans = 0;
        
        unordered_set<char> map;
        
        while(i < n && j < n)
        {
            if(map.find(s[j]) == map.end())
            {
                map.insert(s[j]);
                j++;
                ans = max(ans, j-i);
            }
            else
            {
                map.erase(s[i]);
                i++;
            }
        }
        
        
        return ans;
    }
};