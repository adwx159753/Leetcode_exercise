/*
 * @lc app=leetcode id=1220 lang=cpp
 *
 * [1220] Count Vowels Permutation
 */

// @lc code=start
// #define SOLUTION_1
#define SOLUTION_2

#define mod 1000000007

class Solution {
public:
    int countVowelPermutation(int n) {
#ifdef SOLUTION_2    
/*
        Solution2: dp? -> O(n?) 應該很快? Accepted: 25ms 17.4MB
        這題有點像fib，一個字可以衍生出很多結果
        經過計算後，這些結果有以下特徵:
        
        第N個結果可由第(N-1)得出
          | 1  2  3  4  5  
        --|--------------
        a | 1  1  2  5  8   (e = 8)
        e | 1  2  5  8  18  (a+i = 5+13 = 18)
        i | 1  4  6  13 22  (a+e+o+u = 5+8+7+2 = 22)
        o | 1  2  5  7  15  (i+u = 13+2 = 15)
        u | 1  1  1  2  5   (a = 5)
        --|---------------
          | 5  10 19 35 68
        
        進化 -> 不用vector存，直接用5個變數來執行 Accepted 0ms 5.9MB
        用vector存可以隨時存取想要的資料，但此題僅需計算一次，故採用此方法
*/
        /*
        long long int ans = 0;
        
        vector<vector<long int>> count(5, vector<long int>(n+1, -1));
        
        // 前兩個要自己建
        // 0~4對應a~u
        count[0][0] = 1;
        count[1][0] = 1;
        count[2][0] = 1;
        count[3][0] = 1;
        count[4][0] = 1;
        
        count[0][1] = 1;
        count[1][1] = 2;
        count[2][1] = 4;
        count[3][1] = 2;
        count[4][1] = 1;
        
        int c = 1;
        while(c < n){
            count[0][c+1] = count[1][c]%mod;
            count[1][c+1] = count[0][c]%mod + count[2][c]%mod;
            count[2][c+1] = count[0][c]%mod + count[1][c]%mod + count[3][c]%mod + count[4][c]%mod;
            count[3][c+1] = count[2][c]%mod + count[4][c]%mod;
            count[4][c+1] = count[0][c]%mod;
            c++;
        }
        
        for(int j = 0; j < 5; j++){
            ans = (ans+count[j][n-1])%mod;
        }
        
        return ans;
        */
        
        if(n == 1) return 5;
        long int a=1, e=2, i=4, o=2, u=1;
        int c = 2;
        while(c < n){
            long int at=a, et=e, it=i, ot=o, ut=u;
            a=et%mod;
            e=at%mod + it%mod;
            i=at%mod + et%mod + ot%mod + ut%mod;
            o=it%mod + ut%mod;
            u=at%mod;
            c++;
        }
        
        return (a+e+i+o+u)%mod;
        
#endif
/* ********************************************************************* */
#ifdef SOLUTION_1
/*
        Solution1: 0~4分別對應a~u -> O(n^m): TLE
        1. 找出0~4分別可由那些字母衍生出:
           0 -> {1}
           1 -> {0,2}
           2 -> {0,1,3,4}
           3 -> {2,4}
           4 -> {0}
        2. 由頭印到尾(不用真的印)，找出所有可能
*/
        if(n == 1) return 5;
        int ans = 0;
        vector<vector<int>> derived = {{1}, {0,2}, {0,1,3,4}, {2,4}, {0}};
        for(int i = 0; i < 5; i++){
            vector<int> tmp;
            int size = 1;
            int count = 0;// 計算總格數
            tmp.push_back(i);// 把a~u開頭各印一次
            while(count < n){
                int top = tmp.front(); // 記住當前數字
                tmp.erase(tmp.begin()); // 丟掉最前面
                if(count != n-1) // 如果最後一圈了->不加入其他可能
                    tmp.insert(tmp.end(), derived[top].begin(), derived[top].end()); // 接上所有可能
                size--;
                if(size <= 0){
                    if(count == n-2) ans += tmp.size();
                    count++;
                    size += tmp.size();
                }
            }
        }
        return ans;
#endif
    }
};
// @lc code=end

