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
    pair<int, int> maxPath(TreeNode* root) {
        if (!root) return {INT_MIN, 0};
        
        auto left = maxPath(root->left);
        auto right = maxPath(root->right);

        auto maxVal = max({left.first, right.first, left.second + right.second + root->val});

        return {maxVal, max({left.second + root->val, right.second + root->val, 0})};

    } 

    int maxPathSum(TreeNode* root) {
        return maxPath(root).first;
    }
};
