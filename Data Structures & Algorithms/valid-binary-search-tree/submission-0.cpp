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
    bool validateBST(TreeNode* root, long currMin, long currMax) {
        if (!root) return true;

        if (!(currMin < root->val && root->val < currMax)) return false;

        return (validateBST(root->left, currMin, root->val) &&
                validateBST(root->right, root->val, currMax));
    }

   public:
    bool isValidBST(TreeNode* root) { 
        //T.C: O(n), S.C: O(n) -> stack space
        return validateBST(root, LONG_MIN, LONG_MAX); 
    }
};
