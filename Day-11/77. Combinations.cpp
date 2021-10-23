/*
Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
Example 2:

Input: n = 1, k = 1
Output: [[1]]

*/

class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int i, int n, int k, vector<int>& arr)
    {
        if(arr.size() == k)
        {
            ans.push_back(arr);
            return;
        }
        
        for(int l = i; l <= n; l++)
        {
            arr.push_back(l);
            solve(l+1, n, k, arr);
            arr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> arr;
        solve(1, n, k, arr);
        
        return ans;
    }
};