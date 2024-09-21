/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
//#define SOLUTION_1
#define SOLUTION_2

class Solution {
public:

#ifdef SOLUTION_1
    void backtracking(vector<int>& s, vector<int> tmp, vector<bool> b, vector<int>& all, int i, int &count){
        tmp.push_back(s[i]);
        b[i] = true;
        //cout << s[i] << " ";
        
        if(tmp.size() == s.size()){
            all = tmp;
            count--;
            return ;
        }
        
        for(int a = 0; a < s.size(); a++){
            if(count <= 0) break;
            if(a != i && b[a] != true){
                backtracking(s, tmp, b, all, a, count);
            }
        }
    }
#endif
    
    string getPermutation(int n, int k) {
#ifdef SOLUTION_2        
        /* Solution2: Math...?
           Main idea: We can count the answer directly by doing some math.
           
           Time Complexity: O(n)
           Status: Accepted, 0ms(100.00%), 5.8MB(99.23%)
        */
        /*   
           Example: 
           1. normal: If n=9, k=101135.
              We know to factor from 0!~8! are: [1,1,2,6,24,120,720,5040,40320]
              Therefore, we can count the answer from these number.
              
              step as below:
              we can use "s" to get 1~9
              
              0. ans = ""
              
              1. 1 2 3 4 5 6 7 8 9
                 s = 101135/40320 = 2 -> 3
                 c = 101135%40320 = 20495
                 ans = 3
                 
              2. 1 2 4 5 6 7 8 9
                 s = 20495/5040 = 4 -> 6
                 c = 20495%5040 = 335
                 ans = 36
                 
              3. 1 2 4 5 7 8 9
                 s = 335/720 = 0 -> 1
                 c = 335%720 = 335
                 ans = 361
                 
              4. 2 4 5 7 8 9
                 s = 335/120 = 2 -> 5
                 c = 335%120 = 95
                 ans = 3615
                 
              5. 2 4 7 8 9
                 s = 95/24 = 3 -> 8
                 c = 95%24 = 23
                 ans = 36158
                 
              6. 2 4 7 9
                 s = 23/6 = 3 -> 9
                 c = 23%6 = 5
                 ans = 361589
                 
              7. 2 4 7
                 s = 5/2 = 2 -> 7
                 c = 5%2 = 1
                 ans = 3615897
                 
              8. 2 4
                 s = 1/2 = 0 -> 2
                 c = 1%2 = 1
                 ans = 36158972
              
              9. 4
                 
                 ans = 361589724
        */  // Example 1: n=9, k=101135
        /*
           2. when c = 0: If n=8, k=40152
              when c = 0, s = s-1, and the number will be the current biggest.
              0. ans = ""
              
              1. 1 2 3 4 5 6 7 8
                 s = 40152/5040 = 7 -> 8
                 c = 40152%5040 = 4872
                 ans = 8
                 
              2. 1 2 3 4 5 6 7
                 s = 4872/720 = 6 -> 7
                 c = 4872%720 = 552
                 ans = 87
                 
              3. 1 2 3 4 5 6
                 s = 552/120 = 4 -> 5
                 c = 552%120 = 72
                 ans = 875
                 
              4. 1 2 3 4 6
                 s = 72/24 = 3
                 c = 72%24 = 0
                 
                 therefore, s = 2 -> 3
                 ans = 8753 + 6421
            
              5. ans = 87536421
        */  // Example 2: n=8, k=40152
        
        int fac[9] = {1,1,2,6,24,120,720,5040,40320};
        vector<char> num = {'1','2','3','4','5','6','7','8','9'};
        string ans;
        
        int a = n;
        int s = 0;
        int c = 0;
        
        while(a > 0){
            s = k/fac[a-1];
            c = k%fac[a-1];
            //cout << a << " " << s << " " << c << endl;
            
            if(c != 0){
                ans.push_back(num[s]);
                num.erase(num.begin()+s);
                a--;
                k=c;
            }
            else{
                ans.push_back(num[s-1]);
                num.erase(num.begin()+s-1);
                a--;
                for(int i = a-1; i >= 0; i--){
                    ans.push_back(num[i]);
                }
                break;
            }
            
        }
        
        return ans;
#endif        
        
#ifdef SOLUTION_1
        // Solution1: Backtracking
        // Time Complexity: O(n!) 
        // Status: TLE (200 / 200 test cases passed, but took too long.)
        //
        // Optimize: 
        // 1. Add counter to check if we reach k.
        // 2. No need to record all result, just record the lastest one.
        // 3. If k is big enougth, we can skip some number.
        //    For example: if n=4, k=8, we can just skip 3!(6) and start from 2134.
        //                 The variable "count" will be 8%3!=2, it means we only need to run the 
        //                 loop for 2 times instead of 8 times.
        //
        //    Another example: if n=9, k=100000, we can skip 2*8!(40320) and start from 312456789.
        //                     And count will be 100000%8!=19360.
        //
        //    This algrithm should have an O(n) solution, but is too hard to code.
        
        int fac[9] = {1,1,2,6,24,120,720,5040,40320};
        int start = 0, count = k;
        string ans;
        
        if(n >= 4){
            start = k/fac[n-1];
            count = k%fac[n-1];
            // cout << start << " " << count ;
        }
        
        if(count == 0){ // 每一次count==0，都是當前的最大值(ex: 231, 45321...)
            ans.push_back(start+48);
            for(int i = n; i > 0; i--){
                if(i != start)
                    ans.push_back(i + 48);
            }
            return ans;
        }
        
        vector<int> all;
        vector<int> s;
        
        for(int i = 1; i <= n; i++){
            s.push_back(i);
        }
        
        for(int i = start; i < n; i++){
            vector<int> tmp;
            vector<bool> b(n, false);
            if(count <= 0) break;
            backtracking(s, tmp, b, all, i, count);
        }
        
        for(int i = 0; i < n; i++){
            char c = all[i] + 48;
            ans.push_back(c);
            // cout << all[k-1][i];
        }
        
        
        return ans;
#endif
    }
};
// @lc code=end

