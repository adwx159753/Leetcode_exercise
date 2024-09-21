/*
 * @lc app=leetcode id=1310 lang=cpp
 *
 * [1310] XOR Queries of a Subarray
 */

// @lc code=start

// #define SOLUTION1
#define SOLUTION2

class Solution {
private:
    // int cal = 0;

public:
    int xor_cal(int a, int b) {
        // ++cal;
        int ans = 0;
        int bit = 1;
        while(a > 0 || b > 0) {
            // cout << cal << ": " << a << "," << b << "," << bit << "," << ans << endl;
            ans += (a%2 != b%2) * bit;
            a /= 2;
            b /= 2;
            bit *= 2;
        }
        return ans;
    }
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;

#ifdef SOLUTION1
        /* Solution 1: Just solve it (TLE: 40/42) */
        for(auto a:queries) {
            int tmp = arr[a[0]];
            if(a[0] != a[1]) {
                for(int i = a[0] + 1; i <= a[1]; i++) {
                    tmp = xor_cal(tmp, arr[i]);
                }
            }
            ans.push_back(tmp);
        }
#endif
#ifdef SOLUTION2
        /* Solution 2: Prefix, Accepted, 89ms(19.73%), 9.09%(45.2MB) */ 
        /* 
            1. Prefix all answer from 0 to n.
               Prefix[n] = arr[1] XOR arr[2] ... arr[n]
            2. Because: 
                1. (A XOR B) XOR C = A XOR (B XOR C)
                2. A XOR A = 0
                3. C XOR D = (A XOR B) XOR (A XOR B XOR C XOR D)
               Therefore, arr[n] XOR arr[n+1] XOR arr[n+2] ... arr[m] = Prefix[n] XOR Prefix[m]
         */
        vector<int> prefix;
        int tmp = 0;
        for(int i = 0; i < arr.size(); i++) {
            tmp = xor_cal(tmp, arr[i]);
            prefix.push_back(tmp);
        }

        for(auto a:queries) {
            if(a[0] == 0) ans.push_back(prefix[a[1]]);
            else ans.push_back(xor_cal(prefix[a[0]-1], prefix[a[1]]));
        }
#endif
        return ans;
    }
};
// @lc code=end

