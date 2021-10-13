/*

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.


Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

*/

ass Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int l = 0, r = nums.size()-1;
        vector<int> ans(r+1);
        int k = r;
        
        while(k >= 0)
        {
            if(abs(nums[l]) > abs(nums[r]))
            {
                ans[k] = (nums[l]*nums[l]);
                l++;
                // cout << "if stat " << k << endl;
                k--;
            }
            else
            {
                ans[k] = (nums[r]*nums[r]);
                r--;
                // cout << "else stat " << k << endl;
                k--;
            }
        }
        
        return ans;
        
    }
};