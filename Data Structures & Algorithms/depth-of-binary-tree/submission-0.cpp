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
    int curr = 0;
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        if(!root -> left && !root -> right) return 1;

        int left = 0, right = 0;

        if(root -> left) left = maxDepth(root -> left);
        if(root -> right) right = maxDepth(root -> right);

        int maxDepth = max(left, right);

        return max(curr, 1 + maxDepth); 
    }
};
