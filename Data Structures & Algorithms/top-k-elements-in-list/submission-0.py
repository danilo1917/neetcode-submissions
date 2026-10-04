class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        
        # cada posição i, guarda os elementos que aparecerem i vezes

        # Bucket Sort
        # cada indice recebe os valores que aparecem aquele número de vezes
        # Então, para descobrir os top k, basta vir de tràs pra frente do último preenchido para o primeiro

        bucket = [list() for i in nums]
        lastSeen = -1
        
        mapa = {}

        for i in nums:
            if (i not in mapa):
                mapa[i] = 0
            
            mapa[i] += 1

        lastSeen = -1
        for i, j in mapa.items():
            if (bucket[j-1] is None):
                bucket[j-1] = list()
            bucket[j-1].append(i)

        lista = []
        for i in bucket:
            for j in i:
                lista.append(j)

        return lista[:-k-1:-1]