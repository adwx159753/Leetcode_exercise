/*
 * @lc app=leetcode id=1611 lang=cpp
 *
 * [1611] Minimum One Bit Operations to Make Integers Zero
 */

// @lc code=start
class Solution {
public:
    int pow(int a, int b) {
        int tmp = 1;
        while(b > 0) {
            tmp *= a;
            b--;
        }
        return tmp;
    }
    int minimumOneBitOperations(int n) {
        uint32_t ans = 0;
        uint8_t index = 31;
        bool flag = false;
        int tmp = 0;
        vector<bool> bits(32, 0);

        while(n > 0) {
            bits[index--] = ((n%2) == 1);
            n /= 2;
        }

        for(index = 0; index < 32; index++) {
            if(bits[index] == 1) {
                tmp = (pow(2, (32-index)) - 1);
                if(flag) tmp = 0 - tmp;
                flag = !flag;
                
                ans += tmp;
                // cout << tmp << endl;
            }
        }
        return ans;
    }
};
// @lc code=end

