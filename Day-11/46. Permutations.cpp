/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]

*/

class Solution {
public:
        vector<int> nextPerm(vector<int>& A)
        {
            int n = A.size();
            int i;

            for(i = n-2; i >= 0; i--)
            {
                if(A[i] < A[i+1])
                {
                    break;
                }
            }

            if(i == -1)
            {
                reverse(A.begin(), A.end());
                return A;
            }

            int j;

            for(j = n-1; j > 1; j--)
            {
                if(A[j] > A[i])
                {
                    break;
                }
            }

            swap(A[i], A[j]);
            reverse(A.begin() + i + 1, A.end());

            return A;
        }

        int factorial(int n)
        {
            if(n > 1)
                return n * factorial(n - 1);
            else
                return 1;
        }
    vector<vector<int>> permute(vector<int>& A) {

        vector<vector<int>> arr;
        vector<int> vec;

        int n = A.size();

        long num = factorial(n);
        int i = 0;

        // arr.push_back(A);

        while(i < num)
        {
            A = nextPerm(A);
            arr.push_back(A);
            i++;
        }

        return arr;
    }
};