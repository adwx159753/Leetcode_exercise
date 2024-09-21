/*
 * @lc app=leetcode id=502 lang=cpp
 *
 * [502] IPO
 */

// @lc code=start
class Solution {
private:
    /**
     * @brief Pop the maxinum number and sort the tree.
     * 
     * @param heap 
     * @return int maxinum number
     */
    int PopHeap(vector<int>& heap){
        int i = 1, pop = heap[i];
        heap[1] = heap[heap.size()-1];
        heap[heap.size()-1] = pop;
        heap.erase(heap.end()-1);

        while(i < heap.size()){
            int tmp = heap[i], next = heap.size();
            if((i*2+1) < heap.size()) {
                if(heap[i*2] > heap[i*2+1]) next = i*2;
                else next = i*2+1;
                if(heap[i] < heap[next]){
                    heap[i] = heap[next];
                    heap[next] = tmp;
                }
            }else if(i*2 < heap.size()){
                next = i*2;
                if(heap[i] < heap[next]){
                    heap[i] = heap[next];
                    heap[next] = tmp;
                }
            }
            i = next;
        }
        return pop;
    }
    /**
     * @brief Maxinum Heapify
     * 
     * @param heap 
     */
    void BulidHeap(vector<int>& heap){
        int i = heap.size()-1;
        while(heap[i] > heap[i/2] && (i/2) > 0){
            int tmp = heap[i];
            heap[i] = heap[i/2];
            heap[i/2] = tmp;
            i = i/2;
        }
    }

public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        /**
         * @brief 
         * Solution: Heap and Greedy
         * Accpeted, 291ms(29.34%), 82.1MB(53.52%)
         * Time Complexity: O(nlogn), which n is size of profits and capital.
         * Space Complexity: O(n), which n is size of profits and capital.
         * 0. Build a Heap function by our bare hands!!
         * 1. Sort the data by capital.
         * 2. Push all data into heap until the capital is bigger than w.
         *    -> When capital is bigger than w, pop the heap tree until w starting being 
         *       bigger than the capital.
         * 3. Pop the heap tree until k = 0.
         * 
         * NOTE: 
         * 1. If we don't use sort, time complexity will become O(n^2logn), because we need 
         *    to check the whole vector to find the data which is smaller than w.
         * 2. Heap is the best solution for this topic, it cost the least time to find and 
         *    cost the same time as binary search tree to sort.
         *    e.g. 
         *    0. Maxinum Heap Tree  -> O(1) to find, O(logn) to sort.
         *    1. binary search tree -> O(logn) to find, O(logn) to sort.
         *    2. sorted list        -> O(1) to find, O(nlogn) to sort.
         * 
         */
        vector<pair<int,int>> cp;
        vector<int> heap;
        heap.push_back(-1);

        for(int i = 0; i < profits.size(); i++)
            cp.push_back({capital[i], profits[i]});
        
        sort(cp.begin(), cp.end());

        for(int i = 0; i < cp.size(); i++){
            if(cp[i].first <= w) {
                heap.push_back(cp[i].second);
                BulidHeap(heap);
            }else if(heap.size() > 1) {
                if(heap.size() <= 1) break;
                w += PopHeap(heap);
                k--;
                if(k <= 0) break;
                i--;
            }
        }
        while(k > 0 && heap.size() > 1) {
            w += PopHeap(heap);
            k--;
        }

        // Same Solution, but use k for loop.
        // int index = 0;
        // for(int i = 0; i < k; i++){
        //     for(index; index < cp.size(); index++){
        //         if(cp[index].first <= w) {
        //             heap.push_back(cp[index].second);
        //             BulidHeap(heap);
        //         }else{
        //             break;
        //         }
        //     }
        //     if(heap.size() == 1) break;
        //     w += PopHeap(heap);
        // }

        return w;
    }
};

/*
1\n0\n[1,2,3]\n[1,1,2]
1\n0\n[1,2,3]\n[0,1,2]
2\n0\n[1,2,3]\n[0,9,10]
10\n0\n[1,2,3,4,5,6,7,8,9,10,12,11,13,14,15,16,7,18,19,200,21,202,23,204,50,96,78,89,90]\n[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,18,17,19,20,21,22,23,24,25,26,27,28]
*/
// @lc code=end

