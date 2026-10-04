class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mapa = {}

        for i, v in enumerate(nums):
            if (target-v in mapa.keys()):
                return [mapa[target-v], i]
            
            mapa[v] = i

        return []
        