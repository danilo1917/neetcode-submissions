class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        def build_map(string):
            vec = [0]*26
            for i in string:
                vec[ord(i) - ord('a')]+=1
            return tuple(vec)

        mapa = {}

        for p in strs:
            chave = build_map(p) 
            if (chave in mapa):
                mapa[chave].append(p)
            else:
                mapa[chave] = [p]

        return [v for i, v in mapa.items()]