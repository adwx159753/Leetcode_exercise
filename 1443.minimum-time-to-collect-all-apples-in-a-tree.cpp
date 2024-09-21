/*
 * @lc app=leetcode id=1443 lang=cpp
 *
 * [1443] Minimum Time to Collect All Apples in a Tree
 */

// @lc code=start


/**
 * @brief 
 * 7\n[[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]\n[false,false,true,false,false,true,false]
 * 4\n[[0,1],[1,2],[0,3]]\n[true,true,true,true]
 * 4\n[[0,2],[0,3],[1,2]]\n[false,true,false,false]
 * 4\n[[1,2],[0,2],[0,3]]\n[false,true,false,false]
 * 5\n[[0,3],[0,4],[1,2], [2, 4]]\n[false, true, false, false, false]
 * 35\n[[0,1],[0,2],[1,3],[3,4],[1,5],[2,6],[5,7],[1,8],[6,9],[8,10],[5,11],[10,12],[8,13],[7,14],[12,15],[7,16],[2,17],[1,18],[2,19],[4,20],[5,21],[5,22],[17,23],[6,24],[8,25],[24,26],[10,27],[19,28],[16,29],[26,30],[8,31],[23,32],[21,33],[21,34]]\n[false,true,false,true,false,false,true,false,true,false,true,false,false,true,false,true,false,false,false,true,true,true,false,true,true,false,false,true,false,false,false,true,false,false,false]
 */

class Solution {
public:

    int find_parent(vector<vector<int>>& map, vector<bool>& ha, int i, int parent){
        int ans = 0, tmp = 0;
        for(auto& m:map[i]){
            if(m != parent){
                tmp = find_parent(map, ha, m, i);
                if(tmp > 0 || ha[m]){
                    ans += (tmp+2);
                }
            }
        }

        return ans;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& ha) {
        vector<vector<int>> map(n);

        for(auto e:edges){
            map[e[0]].push_back(e[1]);
            map[e[1]].push_back(e[0]);
        }

        return find_parent(map, ha, 0, -1);
    }
};
// @lc code=end

