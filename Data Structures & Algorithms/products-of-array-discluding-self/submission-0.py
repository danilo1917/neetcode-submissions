class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ida = [1 for i in nums]
        volta = [1 for i in nums]
        
        antes = 1
        
        for i in range(len(nums)):
            if (i-1 >=0):
                ida[i] = (nums[i-1]*antes)

            antes = ida[i]
        
        antes = 1
        for i in range(len(nums)-1,-1,-1):
            if (i+1 < len(nums)):
                volta[i] = (nums[i+1]*antes)
            antes = volta[i]

        return [ida[i]*volta[i] for i in range(len(nums))]
        