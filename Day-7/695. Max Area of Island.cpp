/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

 

Example 1:


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0

*/

class Solution {
public:
    
    int maxArea = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    int dfs(int i, int j, vector<vector<int>>& grid, unordered_set<string>& set)
    {
        string check = to_string(i)+"-"+to_string(j);
        
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0         || set.find(check) != set.end())
        {
            return 0;
        }
        
        int count = 1;
        set.insert(check);
        
        for(int k = 0; k < 4; k++)
        {
            count += dfs(i + dx[k], j + dy[k], grid, set);
        }
        
        return count;
        
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        unordered_set<string> set;
        int area = 0;
        
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    maxArea = max(maxArea, dfs(i, j, grid, set));
                }
            }
        }
        
        return maxArea;
        
    }
};