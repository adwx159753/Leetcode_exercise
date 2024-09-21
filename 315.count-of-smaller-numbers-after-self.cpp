/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

// @lc code=start
// #define SOLUTION_1
#define SOLUTION_2

class Solution {
public:
    void Merge(vector<pair<int,int>>& nums, int b, int m, int e, vector<int>& count){
        
        vector<pair<int,int>> tmp(e-b+1);
        int t = 0;
        int l = b;
        int r = m + 1;
        
        // 由大到小 -> count用加的
        while(l <= m && r <= e){
            if(nums[l].first <= nums[r].first){
                tmp[t++] = nums[r++];
            }else{
                // 發現 l > r 時，將右側整排加進當前count
                // ex: (9,7,1) merge (8,5,3)
                //                    r   e
                // =>  此時9>8，且8之後必為較小，故將 e-r+1=5-3+1=3 加入
                count[nums[l].second] += e-r+1;
                // cout << nums[l].first << " ";
                tmp[t++] = nums[l++];
            }
        }
        
        while(l <= m){
            tmp[t++] = nums[l++];
        }
        while(r <= e){
            tmp[t++] = nums[r++];
        }
        
        for(int i = b; i <= e; i++){
            nums[i] = tmp[i-b];
        }
    }
    
    void MergeSort(vector<pair<int,int>>& nums, int b, int e, vector<int>& count){
        if(b >= e) return ;     // 切割到剩下一個
        int mid = (b + e) / 2;    
        MergeSort(nums, b, mid, count);  // 左子字串
        MergeSort(nums, mid+1, e, count);// 右子字串
        Merge(nums, b, mid, e, count);      // 合併
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        
#ifdef SOLUTION_2
        // Solution 2: Merge Sort
        
        // count: 在Merge時檢查 預設範圍=nums.size() 且全部設為0
        vector<int> count(nums.size(), 0); 
        
        // p: 用來記錄位置
        // ex: {5, 0}, {2, 1}, {6, 2}, {1, 3}
        vector<pair<int,int>> p(nums.size());
        for(int i = 0; i < nums.size(); i++){
            p[i] = {nums[i], i};
        }
        
        
        MergeSort(p, 0, p.size()-1, count);
        
        
        return count;
#endif


#ifdef SOLUTION_1
        // Solution 1: Brute : O(n^2) Time Limit Exceeded (TLE)
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++){
            ans.push_back(0);
            for(int j = i+1; j < nums.size(); j++){
                if(nums[j] < nums[i]){
                    ans[i]++;
                }
            }
        }
        return ans;
#endif

    }
};
// @lc code=end

