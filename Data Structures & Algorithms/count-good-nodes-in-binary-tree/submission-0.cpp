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
    int countGoodNodes(TreeNode* root, int maxVal) {
        if (!root) return 0;

        int left = countGoodNodes(root->left, max(maxVal, root->val));
        int right = countGoodNodes(root->right, max(maxVal, root->val));

        if (root->val >= maxVal) return 1 + (left + right);

        return (left + right);
    }

   public:
    int goodNodes(TreeNode* root) { 
        //T.C: O(n), S.C: O(n)
        return countGoodNodes(root, INT_MIN); 
    }
};
