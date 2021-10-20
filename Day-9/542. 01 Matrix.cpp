/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

*/

class Solution {
public:
    
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    bool isvalid(int i,int j,int m,int n)
    {
        if(i==m||j==n||j<0||i<0)
            return false;
        return true;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        queue<pair<int, int>> Q;
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> dis(m, vector<int> (n, -1));
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 0)
                {
                    Q.push({i, j});
                    dis[i][j] = 0;
                }
            }
        }
        
        while(!Q.empty())
        {
            auto curr = Q.front();
            Q.pop();
            
            for(int k = 0; k < 4; k++)
            {
                int a=curr.first+dx[k];
                int b=curr.second+dy[k];
                
                if(isvalid(a,b,m,n) && dis[a][b] == -1)
                {
                    Q.push({a,b});
                    dis[a][b]=dis[curr.first][curr.second]+1;
                }

            }
            
        }
        
        return dis;
        
    }
};