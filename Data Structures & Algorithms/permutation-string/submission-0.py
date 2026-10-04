class Solution:
    def checkInclusion(self, s1: str, s: str) -> bool:
        hash1 = {}

        for i in s1:
            if i not in hash1:
                hash1[i] = 0
            hash1[i]+=1

        hash2 = {}
        p1 = 0
        p2 = 0
        tam1 = len(s1)
        tam2 = 0

        while(tam2 < tam1 and p2 < len(s)):
            if s[p2] not in hash2:
                hash2[s[p2]] = 0
            hash2[s[p2]]+=1
            p2+=1
            tam2+=1

        if (hash1 == hash2):
            return True
        
        while (p2 < len(s)):
            print(hash1)
            print(hash2)
            print("-------")
            if (hash1 == hash2):
                return True

            hash2[s[p1]]-=1
            if(hash2[s[p1]] == 0):
                hash2.pop(s[p1])
            p1+=1
            if (p2 >= len(s)):
                break
            if s[p2] not in hash2:
                hash2[s[p2]]=0
            hash2[s[p2]]+=1
            p2+=1

        
        if (hash1 == hash2):
            return True
            
        return False
            



                

            
            
