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
    void dfs(vector<TreeNode*> & resp, TreeNode* root, TreeNode* goal){
        resp.push_back(root);
        if (root == goal){
            return;
        }

        if (goal-> val < root-> val)
            dfs(resp, root->left, goal);
        else
            dfs(resp, root->right, goal);
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> r1, r2;

        dfs(r1, root, p);
        dfs(r2, root, q);

        for (auto v: r1){
            cout << v-> val << " ";
        }
        cout << endl;
        for (auto v: r2){
            cout << v-> val << " ";
        }

        int lastIndex = min(r1.size(), r2.size()) -1;

        for (int i=lastIndex; i>=0; i--){
            if(r1[i] == r2[i])
                return r1[i];
        }

        return root;
    }
};
