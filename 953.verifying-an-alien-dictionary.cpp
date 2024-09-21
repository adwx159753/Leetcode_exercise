/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */

// @lc code=start
class Solution {
public:
    bool is_sorted(string& w1, string& w2, string& order){
        for(int i = 0; i < min(w1.size(), w2.size()); i++){
            if(w1[i] != w2[i]){
                if(order.find(w1[i]) > order.find(w2[i])) return false;
                else return true;
                break;
            }
        }
        if(w1.size() > w2.size()) return false;
        else return true;
    }

    bool isAlienSorted(vector<string>& words, string order) {        
        for(int i = 1; i < words.size(); i++)
            if(!is_sorted(words[i-1], words[i], order)) return false;
        return true;
    }
};
// @lc code=end

