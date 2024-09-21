/*
 * @lc app=leetcode id=2251 lang=cpp
 *
 * [2251] Number of Flowers in Full Bloom
 */

// @lc code=start
class Solution {
public:

    vector<int> solution1(vector<vector<int>>& flowers, vector<int>& people){
        // O(nm)
        vector<int> ans(people.size());
        for(vector<int> v:flowers) {
            int start = v[0], end = v[1];
            for(int i = 0; i < people.size(); i++) {
                if(people[i] >= start && people[i] <= end) {
                    ans[i]++;
                }
            }
        }
        return ans;
    }

    vector<int> solution2(vector<vector<int>>& flowers, vector<int>& people){
        // O(nlogn + m)
        vector<int> start, end, ans;
        for(vector<int> v:flowers) {
            start.push_back(v[0]);
            end.push_back(v[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        for(auto p:people) {
            int index1 = upper_bound(start.begin(), start.end(), p) - start.begin();
            int index2 = lower_bound(end.begin(), end.end(), p) - end.begin();

            // cout << index1 << ", " << index2 << endl;

            ans.push_back(index1-index2);
        }

        return ans;
    }

    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // return solution1(flowers, people); // TLE
        return solution2(flowers, people);
    }
};
// @lc code=end

