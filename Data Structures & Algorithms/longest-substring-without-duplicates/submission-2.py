class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # dá pra usar um hash para lookup in O(1)
        # Sempre que a letra se repetir, começa uma nova string ali
        # Pega a maior no fim

        maior = 0
        c = set()
        i = 0
        j = 0
        while j < len(s):
            if (s[j] in c):
                maior = max(maior, len(c))
                while(i < j and s[j] in c):
                    if (s[i] in c):
                        c.remove(s[i])
                    i+=1
                    
            c.add(s[j])
            j+=1

        maior = max(maior, len(c))
        return maior