/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

*/

class Solution {
public:
        
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int, int>> Q;
        int count = 0, tot = 0, days = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        if(m == 0)
        {
            return 0;
        }
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] != 0)
                {
                    tot++;
                }
                
                if(grid[i][j] == 2)
                {
                    Q.push({i, j});
                }
            }
        }
        
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        
        while(!Q.empty())
        {
            int sz = Q.size();
            count += sz;
            
            while(sz--)
            {
                pair<int, int> temp = Q.front();
                Q.pop();
                
                int x = temp.first, y = temp.second;
                
                for(int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    
                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1)
                    {
                        continue;
                    }
                    
                    grid[nx][ny] = 2;
                    Q.push({nx, ny});
                }
            }
            
            if(!Q.empty())
            {
                days++;
            }
        }
        
        if(tot != count)
        {
            return -1;
        }
        
        return days;
    }
};