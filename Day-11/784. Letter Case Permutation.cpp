/*
Given a string s, we can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. You can return the output in any order.

 

Example 1:

Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
Example 2:

Input: s = "3z4"
Output: ["3z4","3Z4"]
Example 3:

Input: s = "12345"
Output: ["12345"]
Example 4:

Input: s = "0"
Output: ["0"]

*/

class Solution {
public:
    vector<string> arr;
    
    void check(string& str, string& ans)
    {
        if(str == "")
        {
            arr.push_back(ans);
            return;
        }
        
        string str1 = str;
        string res = ans;
        
        char ele = str1[0];
        
        if(!(isalpha(str1[0])))
        {
            str1.erase(str1.begin()+0);
            res += ele;
            check(str1, res);
        }
        else
        {
            if(islower(ele))
            {
                res += ele;
                str1.erase(str1.begin()+0);
                check(str1, res);

                ele = toupper(ele);
                string res1 = ans + ele;
                check(str1, res1);
            }
            else
            {
                res += ele;
                str1.erase(str1.begin()+0);
                check(str1, res);
                
                ele = tolower(ele);
                string res1 = ans + ele;
                check(str1, res1);
            }
            
        }
        return;
    }
    
    vector<string> letterCasePermutation(string s) {
        
        string ans = "";
        check(s, ans);
        return arr;
    }
};