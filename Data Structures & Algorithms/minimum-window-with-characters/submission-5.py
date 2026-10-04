class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # Calcula o hash de t
        # Vai abrindo a janela em s até que seja possivel encaixar t lá dentro
        # Tenta diminuir essa janela: para cada 1 passo para a direita, diminui ao máximo o lado esquerdo de modo que t ainda fique lá dentro

        ht = {}
        hs = {}
        for key in t:
            ht.setdefault(key, 0)
            ht[key]+=1

        p1 = 0
        p2 = 0
        falta = len(ht)
        while(p2 < len(s)):
            hs.setdefault(s[p2], 0)
            matchAntes = (s[p2] not in ht) or hs[s[p2]] >= ht[s[p2]]
            hs[s[p2]]+=1
            matchAgora = (s[p2] not in ht) or hs[s[p2]] >= ht[s[p2]]
            if (not matchAntes and matchAgora):
                falta-=1
            if (falta == 0):
                break

            p2+=1

        if (falta):
            return ""
        # aqui tenho um match, não necessariamente o menor
        # tenta aumentar e para cada aumento, remove o máximo possível da esquerda
        while(p1 < p2):
            ht.setdefault(s[p1], 0)
            if (hs[s[p1]]-1 >= ht[s[p1]]):
                hs[s[p1]]-=1
                p1+=1
            else:
                break

        bestStr = s[p1:p2+1]
        bestTam = len(bestStr)
        p2+=1

        while (p2 < len(s)):
            hs.setdefault(s[p2], 0)
            hs[s[p2]]+=1
            # print(bestStr)
            while(p1 < p2):
                ht.setdefault(s[p1], 0)
                if (hs[s[p1]]-1 >= ht[s[p1]]):
                    hs[s[p1]]-=1
                    p1+=1
                else:
                    break
                    
            if (p2 - p1 < bestTam):
                bestTam = p2 - p1
                bestStr = s[p1:p2+1]

            p2+=1

        if (p2 - p1 < bestTam):
            bestTam = p2 - p1
            bestStr = s[p1:p2+1]

        return bestStr

        
