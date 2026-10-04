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
        if(!root) return {};
        vector<vector<int>> resp;

        queue<TreeNode*> fila;

        fila.push(root);
        fila.push(new TreeNode(1001));

        vector<int> curr;
        while(!fila.empty()){
            auto front = fila.front();
            fila.pop();

            if (front->val == 1001){
                resp.push_back(curr);
                curr.clear();
                if(fila.empty()) break;
                fila.push(front);
            } else {
                curr.push_back(front->val);

                if (front->left){
                    fila.push(front->left);
                }
                if(front->right){
                    fila.push(front->right);
                }
            }
        }

        return resp;

    }
};
