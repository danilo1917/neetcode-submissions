class Solution:
    def tp(self, nums: List[int], l1: int, l2:int, target: int, results: set, l0: int) -> List[int]:
        p1 = l1
        p2 = l2

        while (p1 < p2):
            if (nums[p1] + nums[p2] > target):
                p2-=1
                continue
            if (nums[p1] + nums[p2] < target):
                p1+=1
                continue
            results.add((nums[l0], nums[p1], nums[p2]))
            p1+=1
            p2-=1

    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # Para cada valor resolve o 2 pointers
        # Como tem que ser O(1) de memória, temos que usar o 2 pointers na lista ordenada.
        # ENtão, ordena
        # Para cada valor a, resolve o two pointers na frente com target -a
        # Simples

        nums.sort()
        results = set()
        for i, j in enumerate(nums):
            self.tp(nums, i + 1, len(nums)-1, -j, results, i)
        

        return [list(i) for i in results]
        