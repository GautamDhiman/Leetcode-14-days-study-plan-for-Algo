/*
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "God Ding"
Output: "doG gniD"

*/

class Solution {
public:
    string reverseWords(string s) {
        
        vector<string> arr;
        string str;
        
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != ' ')
            {
                str += s[i];
            }
            else
            {
                arr.push_back(str);
                str = "";
            }
        }
        
        arr.push_back(str);
        
        s = "";
        
        for(auto st : arr)
        {
            // cout << st << " ";
            reverse(st.begin(), st.end());
            s += st+' ';
        }
        
        s.pop_back();
        return s;
        
    }
};