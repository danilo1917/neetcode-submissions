class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        maxVal = 0
        conj = set(nums)
        run = 0
        i = 0
        while i < len(nums):
            val = nums[i]
            if (val - 1 not in conj):
                run = 1
                while(val + 1 in conj):
                    run+=1
                    val+=1
                maxVal = max(run, maxVal)
            i+=1
        return max(run, maxVal)
        