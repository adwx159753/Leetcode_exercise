/*
 * @lc app=leetcode id=1530 lang=cpp
 *
 * [1530] Number of Good Leaf Nodes Pairs
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
    ****************************** Accepted ******************************
    Solution: DFS, and record the path of all leaves.
    Time Complexity = O((n^2)*logn)
       - Run thought the whole tree -> O(n)
       - Needs to check the distance of each 2 leave -> O((n/2)^2)
       - We also needs to consider about the length of path -> O(logn)
       - The answer will be O(n + ((n/2)^2)*logn) => O((n^2)*logn)
    Space Complexity = O(nlogn)
       - We should store all path of each leave -> O(n/2 * logn)
       - The answer will be O(n/2 * logn) = O(nlogn)

    113/113 cases passed (65 ms)
    Your runtime beats 36.68 % of cpp submissions
    Your memory usage beats 52.88 % of cpp submissions (35.1 MB)

    Update:
    1. pass by value -> pass by reference.
    113/113 cases passed (57 ms)
    Your runtime beats 43.48 % of cpp submissions
    Your memory usage beats 96.37 % of cpp submissions (30.7 MB)

    **********************************************************************
*/
class Solution {
    vector<string> v;
public:
    
    void dfs(TreeNode* root, int& distance, string& path) {
        if(!root->left && !root->right) {
            /*find leaf*/
            v.push_back(path);
            // cout << root->val << "," << path << endl;
        } else{
            if(root->left){
                path += "L";
                dfs(root->left, distance, path);
                path.erase(path.end()-1);
            }
            if(root->right) {
                path += "R";
                dfs(root->right, distance, path);
                path.erase(path.end()-1);
            }
        }
    }
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        string path = "0";
        // Time Complexity = O(n)
        dfs(root, distance, path);
        
        /* Time Complexity = O((n / 2)^2 * log(n)) = O((n^2)*logn) */
        for(int i = 0; i < v.size()-1; i++) {                               // O(n/2)
            for(int j = i+1; j < v.size(); j++) {                           // O(n/2)
                for(int k = 1; k < min(v[i].size(), v[j].size()); k++) {    // O(logn)
                    if(v[i][k] != v[j][k]){ // find different
                        // distance of current 2 leaves is the sum of the different path.
                        // ex: 0LL vs ORR, the distance is 2 + 2 = 4.
                        if((v[i].size() - k) + (v[j].size() - k) <= distance) ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

