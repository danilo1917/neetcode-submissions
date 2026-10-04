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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // Bfs the tree, since we know the amount of nodes in each level, it is quite simple        
        string data = "";

        queue<TreeNode*> fila;

        fila.push(root);

        while(!fila.empty()){
            auto front = fila.front();
            fila.pop();

            if (data.size() == 0){
                if (front)
                    data+= to_string(front->val);
                else
                    data+= "_";
            } else {
                if (front)
                    data+= "," + to_string(front->val);
                else
                    data+= ",_";
            }

            if (front){
                fila.push(front->left);
                fila.push(front-> right);
            }
        }

        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data << "\n";
        vector<TreeNode*> vetor;
        int i =0;
        while(i < data.size()){
            char c = data[i];
            string val;
            while(i < data.size() && c!= ','){
                val+=c;
                i++;
                c = data[i];
            }
            if (val == "_"){
                vetor.push_back(nullptr);
            } else {
                vetor.push_back(new TreeNode(stoi(val)));
            }
            i++;
        }


        int p1 = 1;
        if (vetor.size() == 1) return vetor[0];

        for (int i=0; i< vetor.size(); i++){
            if (!vetor[i]){
                continue;
            }
            vetor[i]->left= p1 < vetor.size() ? vetor[p1]: nullptr;
            vetor[i]->right= p1+1 < vetor.size() ? vetor[p1+1]: nullptr;
            p1+=2;
        }


        return vetor[0];

        return nullptr;

    }
};
