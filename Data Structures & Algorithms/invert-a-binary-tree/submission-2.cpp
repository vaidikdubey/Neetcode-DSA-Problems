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
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL; //Edge case, no root
        if(!root -> left && !root -> right) return root; //Edge case, no child

        TreeNode *left = NULL;
        if(root -> left) {//If left exists, store it
            left = root -> left;
        }

        root -> left = root -> right; //Swap right to left

        root -> right = left; //Update right value to stored left value

        invertTree(root -> left); //Recursive call for left subtree
        invertTree(root -> right); //Recursive call for right subtree
        
        //Return root
        return root; //T.C: O(n), S.C: O(h): h -> height of tree
    }
};
