/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        // Soluion1: 每一格都是左+上的合(由於1用掉了，改用-1，最後*-1)
        //      Status: Accepted 0ms(100.00%), 7.5MB(91.84%)
        //      1. 在邊框填上-1
        //      2. 如果邊框遇到1，則後續不用填-1
        
        int n = obs.size();
        int m = obs[0].size();
        
        for(int i = 0; i < n; i++) {
            if(obs[i][0] == 1) break;
            else if(obs[i][0] == 0) obs[i][0] = -1;
        }
        
        for(int i = 0; i < m; i++) {
            if(obs[0][i] == 1) break;
            else if(obs[0][i] == 0) obs[0][i] = -1;
        }
        /*
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(obs[i][j] != -1) cout << " " ;
                cout << obs[i][j] << ",";
            }
            cout << endl;
        }
        */
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(obs[i][j] == 1) continue;
                if(obs[i-1][j] != 1) obs[i][j] += obs[i-1][j]; 
                if(obs[i][j-1] != 1) obs[i][j] += obs[i][j-1];
            }
        }
        
        if(obs[n-1][m-1] == 1) return 0;
        else if(obs[0][0] == 1) return 0;
        else return obs[n-1][m-1]*-1;
    }
};
// @lc code=end

