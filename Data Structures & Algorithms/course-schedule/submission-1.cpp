class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // b->a;
        // Ordenação topológica. Faz o grafo, salva os graus dos nós, 
        // Enquanto houver nó de grau zero, começa dele 
        // Processa. Tira 1 dos graus dos filhos
        
        // Não precisa;
        // Salva os graus e um set com os zeroCandidates;
        // Enquanto zeroCandidates tiver elemento vai processando

        // Grau de entrada

        vector<vector<int>> grafo(numCourses);
        vector<int> graus(numCourses);
        set<int> zeroes;
        for (auto c: prerequisites){
            auto a = c[0];
            auto b = c[1];
            graus[a]++;
            grafo[b].push_back(a);
        }

        for (int i=0; i<numCourses; i++){
            if (graus[i] == 0){
                zeroes.insert(i);
            }
        }

        int processed = 0;

        while(zeroes.size()){
            auto first = *zeroes.begin();
            processed++;
            zeroes.erase(zeroes.begin());

            for (auto vz: grafo[first]){
                graus[vz]--;
                if (graus[vz] == 0){
                    zeroes.insert(vz);
                }
            }
        }

        return processed == numCourses;
    }
};
