/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */

// @lc code=start
class Solution {
private:
    vector<int> num;  // 
    vector<char> exp; // 
    vector<int> ans;
public:

    int divide_and_conquer(int len) {
        if(len >= 3) {
            /* 
                ans.push_back(...)
                divide_and_conquer(1) + divide_and_conquer(len-1) 
                divide_and_conquer(2) + divide_and_conquer(len-2) 
                .
                .
                .
                divide_and_conquer(len-1) + divide_and_conquer(1) 
            */
        } else {
            /* f(2), Cal the number */
        }

    }
    vector<int> diffWaysToCompute(string expression) {
        /* 
            Solution: Divide And Conquer

            To solve this question, we should know how many answer will it be first.
            Assume f(1) means 1 number and 0 expression, and f(2) means 2 number and 1 expression: 
            f(1) = 1
            f(2) = f(1)*f(1) = 1
            f(3) = f(1)*f(2) + f(2)*f(1) = 1+1 = 2
            f(4) = f(1)*f(3) + f(2)*f(2) + f(3)*f(1) = 2+1+2 = 5
            .
            .
            .
            f(n) = f(1)*f(n-1) ......
            Now we know how the answers from, we can divide the function as above.

            hints: 
            1. we can divide the function until it become f(2).        

        */

        int tmp = 0;
        for(auto a:expression) {
            if(a == '+' || a == '-' || a == '*') {
                exp.push_back(a);
                num.push_back(tmp);
                tmp = 0;
            } else {
                tmp = tmp * 10 + (a - '0');
            }
        } 
        num.push_back(tmp);

        // for(auto a:num) 
        //     cout << a << " ";
        // cout << endl;
        // for(auto a:exp) 
        //     cout << a << " ";
        
        return ans;
    }
};
// @lc code=end

