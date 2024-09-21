/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
/*
[[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /**
         * @brief 
         * Solution: Binary Search (with base-n)
         * 1. Same as binary search, but the index should consider as base-n.
         * 2. For example, when m = 3, n = 4, and the index = 9:
         *    For base-4, we can get the data matrix[9/4][9%4] = matrix[2][1]
         * 
         */
        int m = matrix.size();
        int n = matrix[0].size();
        int max = (m * n), min = 0;

        while(max > min) {
            int index = (max+min)/2;
            int tmp = matrix[index / n][index % n]; 
            // cout << "(" << max << "," << min << ") : " << tmp << "\n";
            if(target > tmp) {
                min = index+1;
            }else if(target < tmp) {
                max = index;
            }else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

