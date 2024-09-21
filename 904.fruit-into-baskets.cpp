/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start

class Solution {
private:
    /**
     * @brief 
     * Solution2: Same idea as solution1, but use unordered_map instead of set.
     * Accepted, 184ms(60.18%), 71.1MB(83.38%)
     * Time Complexity: O(n)
     * Space Complexity: O(1) -> There are only 3 type of fruit being store.
     * 1. We still need to check the fruit types of basket, but don't want to process
     *    it for every loop. Therefore, we need to count the number of each type.
     * 2. When we notice there are more than 2 types of fruit in the basket, we need 
     *    to take the fruit out of the basket, when the one of them becomes 0, erase 
     *    it from the map. Keep doing this until there are only 2 type of fruit in 
     *    the basket.
     * 
     */
    int solution2(vector<int>& f) {
        unordered_map<int,int> b;
        int f1 = 0, f2 = 1, ans = 0;
        b[f[f1]]++;
        while(f2 < f.size()) {            
            b[f[f2]]++;
            while(b.size() > 2){
                ans = max(ans, f2-f1);
                b[f[f1]]--;
                if(b[f[f1]] <= 0) b.erase(f[f1]);
                f1++;
            }
            f2++;
        }
        ans = max(ans, f2-f1);
        return ans;
    }

    /**
     * @brief 
     * Solution1: Two Pointers
     * Status: TLE, 70/91 cases passed(N/A)
     * Time Complexity: O(n^2)
     * Space Complexity: O(1) -> "set" will only store 2~3 characters.
     * 1. Two pointer f1 & f2, use set the check if there are 3 types of fruit
     * 2. If the types of fruit are less than 2 types, f2++, else f1++.
     * 3. The answer is the maxinum diff of f2 and f1.
     * 
     */
    int solution1(vector<int>& f) {
        int f1 = 0, f2 = 1, ans = 0;
        while(f2 < f.size()){
            set<int> baskets;
            for(int i = f1; i <= f2; i++)
                baskets.insert(f[i]);
            
            if(baskets.size() > 2) {
                ans = max(ans, f2-f1);
                f1++;
                continue;
            }
            f2++;
        }
        ans = max(ans, f2-f1);
        return ans;
    }

public:
    int totalFruit(vector<int>& f) {
        // return solution1(f);
        return solution2(f);
    }
};
/*
[0,1,0,2]
[3,3,3,1,2,1,1,2,3,3,4]

*/
// @lc code=end

