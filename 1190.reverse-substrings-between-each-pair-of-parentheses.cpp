/*
 * @lc app=leetcode id=1190 lang=cpp
 *
 * [1190] Reverse Substrings Between Each Pair of Parentheses
 */

// @lc code=start
/*
    24/38 cases passed (N/A) -> Pass, erase current layer when meeting ')'.
        Testcase
            "sxmdll(q)eki(x)"
        Answer
            "sxmdllqekixq"
        Expected Answer
            "sxmdllqekix"

    ****************************** Accepted ******************************
    Solution (Strategy): 
    1. When ever you meet the '(', add one layer.
    2. From '(' to ')', store all characters into current layer.
    3. When every you meet the ')', reverse the current layer, and then minus one layer.

    Time Complexity: O(n)
    Space Complexity: O(n)
    38/38 cases passed (0 ms)
    Your runtime beats 100 % of cpp submissions
    Your memory usage beats 45.73 % of cpp submissions (8 MB)

    Update:
    1. Use pass by reference instead of pass by value to reverse function.

    Little progress: reduce the memory usage. (Maybe not)
    38/38 cases passed (0 ms)
    Your runtime beats 100 % of cpp submissions
    Your memory usage beats 50.36 % of cpp submissions (7.9 MB)
    ***********************************************************************
 */


class Solution {
public:
    string reverse(string& s) {
        string tmp;
        for(int i = s.size()-1; i >=0; i--) tmp += s[i];
        return tmp;
    }
    string reverseParentheses(string s) {
        vector<string> v(1);
        int layer = 0;
        for(auto& c:s) {
            if(c == '(') {
                v.push_back("");
                layer++;
            } else if(c == ')'){
                v[layer-1] += reverse(v[layer]);
                v[layer--] = "";
            } else {
                v[layer] += c;
            }
        }

        return v[layer];
    }
};
// @lc code=end

