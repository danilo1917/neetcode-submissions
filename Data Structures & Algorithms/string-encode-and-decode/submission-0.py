class Solution:

    def encode(self, strs: List[str]) -> str:
        final = ""
        for i in strs:
            final+=f"{len(i)}#{i}"


        return final


    def decode(self, s: str) -> List[str]:
        c=0
        lista = []
        while c < len(s):
            numero = ""
            while s[c] != '#':
                numero+=s[c]
                c+=1
            c+=1
            lista.append(s[c:c+int(numero)])
            c+=int(numero)

        return lista

            