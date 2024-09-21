/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
class Solution {
public:
    bool checkSubarraySum(vector<int>& n, int k) {
        int sum = 0;
        unordered_map<int,int> tmp{{0,0}};

        for(int i = 0; i < n.size(); i++){
            /** 
             * [23,2,6,4,7]\n6
             * [23,2,6,4,7]\n13
             * [23,2,4,6,6]\n7
             * [1,2,12]\n6
             * [5,0,0,0]\n3
             * The length of the subarray is at least two, can not 
             * use the divisible number directly.
             */
            sum += n[i];
            //cout << sum << ":" << tmp[(sum%k)] << endl;
            if(!tmp.count(sum%k)) {
                tmp[(sum%k)] = i+1;
            }else if(i > tmp[(sum%k)]) {
                return true;
            }
        }


        return false;
    }
};
// @lc code=end

