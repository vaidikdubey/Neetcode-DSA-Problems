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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL); //Level marker

        while (!q.empty()) {
            vector<int> level;

            while (!q.empty() && q.front() != NULL) {
                TreeNode* node = q.front();
                q.pop();

                if (node) {
                    level.push_back(node->val);

                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }

            res.push_back(level);

            q.pop();  // Remove NULL for previous level

            if (!q.empty()) {
                q.push(NULL);
            }
        }

        return res; //T.C: O(n), S.C: O(n)
    }
};
