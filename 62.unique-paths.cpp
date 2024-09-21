/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    
    int uniquePaths(int m, int n) {
        /* 
        Solution 1. 排列組合 -> C(m + n - 1 - 1)取(n - 1) 
           1. Runtime Error: 數字太大，overflow
              -> solve: 不分up和down，直接用除的
           2. double數字太大掉位的問題
              -> 沒解決，但讓數字不那麼大了
        */
        
        m = m + n - 1 - 1;
        n = n - 1;
        
        int dif = (m-n);
        if(dif > n) dif = n;
        
        double ans = 1;
        for(int i = 1; i <= dif; i++){
            ans = ans * m;
            ans = ans / i;
            m--;
            
        }
        
        return ans;
    }
};
// @lc code=end

