/*
 * @lc app=leetcode id=2134 lang=cpp
 *
 * [2134] Minimum Swaps to Group All 1's Together II
 */

// @lc code=start
class Solution
{
public:
    /*
    ************************** Accepted **************************
    Solution: Sliding Window
    1. Check the number of "1", and set it as the window size.
    2. The minimum "0" in window is the answer.
    Hint:
    1. Do not check the whole window every time, just check the
       element of start and end.
    2. Should check the all possibility, therefore, the head of
       the window should start from 0 to nums.size()-1.

    63/63 cases passed (70 ms)
    Your runtime beats 48.72 % of cpp submissions
    Your memory usage beats 57.56 % of cpp submissions (83.1 MB)
    **************************************************************
    */

    int minSwaps(vector<int> &nums)
    {
        int ans = 0;
        int left = 0, right = 0;
        int count = 0;
        int tmp = 0;

        for (auto a : nums)
            count += a;
        right = count - 1;

        for (int i = 0; i < count; i++)
            if (nums[i] == 0)
                ans++;
        tmp = ans;

        while (left != nums.size() - 1)
        {
            if (nums[left] == 0)
                tmp--;
            left++;
            right = (right + 1) % nums.size();
            if (nums[right] == 0)
                tmp++;
            if (tmp < ans)
                ans = tmp;
            // cout << left << "," << right << "," << tmp << "\n";
        }

        return ans;
    }
};
// @lc code=end
