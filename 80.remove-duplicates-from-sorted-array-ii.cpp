/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*
            Solution: kinda like two pointer...
            Time Complexity: O(n)
            Status: Accepted, 11ms(49.20%), 11.2MB(15.65%)
        */
        
        int count = 0, ans = 0;
        
        vector<int> tmp;
        for(int i = 0; i < nums.size(); i++){
            if(i != 0)
                if(nums[i] != nums[i-1])
                    count = 0;
            count++;
            while(count >= 2 && i < nums.size()-1){
                if(nums[i] != nums[i+1])
                    break;
                i++;
            }
            ans++;
            tmp.push_back(nums[i]);
        }
        nums = tmp;
        return ans;
    }
};
// @lc code=end

