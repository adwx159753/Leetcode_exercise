/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
// #define SOLUTION1
// #define SOLUTION2
#define SOLUTION3

class Solution {
public:
    
    
//Solution3: 遞迴 (額外function)
#ifdef SOLUTION3
    bool solution3(int i, int j, string p, string s){
        if(i < 0 && j < 0){// 全部找完
            return true;
        }else if(i < 0 && j >= 0){// p用完了，s還有剩
            return false;
        }else if(i >= 0 && j < 0){// s用完了，P還有剩 => 須看p[i]是否為*
            if(p[i] != '*'){
                return false;
            }else{// 一直檢查是否有*
                return solution3(i-2, j, p, s);
            }
        }
        

        
        if(s[j] == p[i] || p[i] == '.'){// 找到匹配
            return solution3(i-1, j-1, p, s);
        }
        
        if(p[i] == '*'){
            if(p[i-1] != s[j] && p[i-1] != '.'){// 重複0次
                return solution3(i-2, j, p, s);
            }else if(p[i-1] == s[j] || p[i-1] == '.'){// 重複多次 or 重複0次都跑過
                // 需要重複0次 ex: s = "aaa"
                //                p = "aa*a*a*aa"
                return (solution3(i, j-1, p, s) || solution3(i-2, j, p, s));
            }
        }
        
        /* 
        // 此判斷式與上面兩個if的範圍互斥且聯集為宇集，因此在最後return false即可
        if(p[i] != '*' && s[j] != p[i] && p[i] != '.'){//有任一不匹配
            return false;
        }
        */
        
        return false;
    }
#endif   
//Solution3   
    
    
    bool isMatch(string s, string p) {
        
//Solution3: 遞迴 (從後往前找)
#ifdef SOLUTION3
        int i = p.size()-1;
        int j = s.size()-1;
        
        if(p == ".*"){
            return true;
        }
        
        return solution3(i,j,p,s);
#endif
//Solution3       
        
        
        
//Solution2: 遞迴 (https://www.cnblogs.com/grandyang/p/4461713.html)
#ifdef SOLUTION2
        if(p.empty()) 
            return s.empty();
        
        if(p.size() == 1)// 找到最後一位
            return ((s.size() == 1) && (s[0] == p[0] || p[0] == '.'));
        
        if(p[1] != '*'){
            if(s.empty()) return false;
            return ((s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1)));
        }
        
        while(!s.empty() && (s[0] == p[0] || p[0] == '.')){
            if(isMatch(s, p.substr(2)))
                return true;
            s = s.substr(1);
        }
        return isMatch(s, p.substr(2));
#endif
//Solution2
        
        
        
        
//Solution1: 直接檢查 : Fail (有許多不用遞迴無法解決的問題)
#ifdef SOLUTION1
        if(p == ".*" || s == p){
            return true;
        }else if(p.size() < s.size()){
            return false;
        }
        int check = 0;
        string ans;
        for(int i = 0; i < p.size(); i++){
            for(int j = check; j < s.size(); j++){
                if(p[i] == s[j] || p[i] == '.'){// 找到匹配
                    ans.push_back(s[j]);
                    check++;
                    break;
                }else if(p[i] == '*'){// 遇到*代表重複前字元0次~多次
                    if(p[i-1] == s[j] || p[i-1] == '.'){// 重複多次
                        ans.push_back(s[j]);
                        check++;
                        continue;
                    }else{// 重複0次
                        break;
                    }
                }else if(p[i] != s[j] && p[i+1] != '*'){
                    return false;
                }
            }
        }
        
        cout << ans;
        if(ans == s)
            return true;
        else
            return false;
#endif
//Solution1
    }
};
// @lc code=end

