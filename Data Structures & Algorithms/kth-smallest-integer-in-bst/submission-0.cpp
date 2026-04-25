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

class Solution {
    void findNode(TreeNode* node, vector<int>& tmp) {
        if (!node) return;

        findNode(node->left, tmp);

        if (tmp[0] == 0) return;

        tmp[0]--;

        if (tmp[0] == 0) {
            tmp[1] = node->val;
            return;
        }

        findNode(node->right, tmp);
    }

   public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> tmp(2);
        tmp[0] = k;

        findNode(root, tmp);
        
        return tmp[1]; //T.C: O(n), S.C: O(n) -> worst case
    }
};
