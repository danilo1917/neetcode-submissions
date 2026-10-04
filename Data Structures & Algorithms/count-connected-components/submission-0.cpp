class Solution {
public:
    void isCon(vector<vector<int>>&grafo, int i, vector<bool>& visitados){
        if (visitados[i]) return;
        visitados[i] = true;

        for (auto c: grafo[i]){
            isCon(grafo, c, visitados);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> grafo(n);

        for (auto &c: edges){
            grafo[c[0]].push_back(c[1]);
            grafo[c[1]].push_back(c[0]);
        }

        vector<bool> visit(n);
        int qtd = 0;
        for (int i=0; i<n; i++){
            if (visit[i]) continue;
            qtd++;
            isCon(grafo, i, visit);
        }

        return qtd;
    }
};
