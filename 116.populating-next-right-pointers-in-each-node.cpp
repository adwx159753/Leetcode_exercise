/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        /**
         * @brief 
         * Solution: Level order
         * Time Complexity: O(n)
         * Accepted: 73ms(5.07%), 18.5MB(5.93%) Why its so slow?
         * 1. Split these nodes by Level, and store them into vector.
         * 2. Use for loop to chain these node from left to right.
         * 
         */
        if(!root) return root;

        vector<Node*> tmp;
        tmp.push_back(root);

        int count = 1;
        while(!tmp.empty()){
            Node* a = new Node;
            a = tmp.front();
            tmp.erase(tmp.begin());

            if(a->left) tmp.push_back(a->left);
            if(a->right) tmp.push_back(a->right);
            
            count--;

            if(count == 0){
                count = tmp.size();
                for(int i = 0; i < count-1; i++)
                    tmp[i]->next = tmp[i+1];
            }
        }
        return root;
    }
};
// @lc code=end

