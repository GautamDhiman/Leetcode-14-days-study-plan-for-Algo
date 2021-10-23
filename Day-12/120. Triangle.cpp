/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10

*/

class Solution {
public:
    
    int dp[201][201];
    
    int solve(int i, int j, vector<vector<int>>& triangle)
    {
        if(i >= triangle.size())
        {
            return 0;
        }
        
        if(j >= triangle[i].size())
        {
            return 0;
        }
        
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        return dp[i][j] = min(triangle[i][j] + solve(i+1, j, triangle), triangle[i][j] +                solve(i+1, j+1, triangle));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, triangle);
        
    }
};