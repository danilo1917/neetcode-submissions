class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int pos, vector<vector<bool>>& visitados, int x, int y){
        if (x < 0 || x >= board.size()) return false;
        if ( y < 0 || y>= board[0].size()) return false;

        if (visitados[x][y]) return false;
        visitados[x][y] = true;
        if (pos == word.size()) return true;
        cout << word[pos]<< endl;
        bool ans = false;
        if (y+1 < board[0].size() && board[x][y+1] == word[pos]){
            ans = ans || dfs(board, word, pos + 1, visitados, x, y+1);
        }
        if (x-1>=0 && board[x-1][y] == word[pos]){
            ans = ans || dfs(board, word, pos + 1, visitados, x-1, y);
        }
        if (x+1<board.size() && board[x+1][y] == word[pos]){
            ans = ans || dfs(board, word, pos + 1, visitados, x+1, y);
        }
        if (y-1 >= 0 && board[x][y-1] == word[pos]){
            ans = ans || dfs(board, word, pos + 1, visitados, x, y-1);
        }
        
        visitados[x][y] = false;
        return ans;

    }
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        vector<vector<bool>> visitados(board.size(), vector<bool>(board[0].size()));

        for (int i=0; i< board.size(); i++){
            for (int j=0; j< board[0].size(); j++){
                if (board[i][j] == word[0]){
                    ans = ans || dfs(board, word, 1, visitados, i, j);
                }
            }
        }

        return ans;
    }
};
