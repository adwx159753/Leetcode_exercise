/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x){
        long int reverse = 0;
        int temp = x;
        while(x>0){
            reverse = reverse*10 + x%10;
            x=x/10;
        }
        if(reverse == temp){return true;}
        else{return false;}
    }
};
// @lc code=end

