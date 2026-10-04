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
    vector<int> isValid(TreeNode* root) {
        if(!root) return {true, INT_MIN, INT_MAX};

        auto left = isValid(root->left);
        if(!left[0]) return {0,INT_MIN, INT_MAX};
        auto right = isValid(root->right);
        if(!right[0]) return {0,INT_MIN, INT_MAX};

        bool clause = left[0] && right[0] && root->val > left[1] && root->val < right[2];
        
        return {clause, max({root->val, right[1], left[1]}), min({root->val,right[2],left[2]})};
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root)[0];
    }
};
