/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

*/

class Solution {
public:
    
    // int arr[46];
    
//     int dp(int n)
//     {
//         if(n == 0)
//         {
//             return 1;
//         }
        
//         if(arr[n] != -1)
//         {
//             return arr[n];
//         }
        
//         if(n >= 2)
//         {
//             arr[n] = climbStairs(n-1) + climbStairs(n-2);
//         }
//         else
//         {
//             arr[n] = climbStairs(n-1);
//         }
        
//         return arr[n];
//     }
    
    int climbStairs(int n) {
        
        // memset(arr, -1, sizeof(arr));
        // return dp(n);
        
        int dp[n+1];
        
        dp[0] = 1;
        
        for(int i = 1; i <= n; i++)
        {
            if(i >= 2)
            {
                dp[i] = dp[i-1]+dp[i-2];
            }
            else
            {
                dp[i] = dp[i-1];
            }
        }
        
        return dp[n];
        
    }
};