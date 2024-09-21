/*
 * @lc app=leetcode id=2147 lang=cpp
 *
 * [2147] Number of Ways to Divide a Long Corridor
 */

// @lc code=start
class Solution {
public:
    int numberOfWays(string corridor) {
        /*
            Solution:   每2個座位算一個群組，每個群組之間的植物數量+1即為分割的可能數量(p+1)
                        將所有群組之間的可能性相乘，即可得到解答
            Time Complexity:    O(n)
            Space Complexity:   O(1)
        */

        if(corridor.size() < 2) return 0;

        long long int ans = 1;
        int s = 0;
        int p = 0;
        int count_s = 0;

        for(char c:corridor) {
            if (c == 'S') s++;      // 計算座位數量
            else if(s == 2) p++;    // 當出現兩個座位，計算植物數量
            
            if(s == 3){ // 出現第三個座位時，結算植物數量
                ans = ((ans * (p+1)) % (1000000007));   // 每個間隔的可能性相乘
                p = 0;  // 重新計算植物
                s = 1;  // 重新數座位
            }
        }
        if((s != 2)) ans = 0;
        return ans;
    }
};
// @lc code=end

