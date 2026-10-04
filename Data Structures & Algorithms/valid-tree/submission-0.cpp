class Solution {
public:
    int count = 0;
    void isCon(vector<vector<int>>&grafo, int i, vector<bool>& visitados){
        if (visitados[i]) return;
        visitados[i] = true;

        count++;
        for (auto c: grafo[i]){
            isCon(grafo, c, visitados);
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> grafo(n);

        for (auto &c: edges){
            grafo[c[0]].push_back(c[1]);
            grafo[c[1]].push_back(c[0]);
        }

        if (edges.size() != n-1) return false;
        vector<bool> visitados(n);
        isCon(grafo, 0, visitados);
        return edges.size() == n-1 && count == n;
    }
};
