class Solution:
    def trap(self, heights: List[int]) -> int:
        # The idea here is that each position must see the taller one in its front
        # So we can use a vector to store it from the end to the beginning for each position

        # we do it onward and backward and get the minimum of both highest values
        # then we sum the diff from that position to the minimum difference of both values
        # from right and left

        maxAtual = 0
        ida = [0]*len(heights)
        for i in range(1, len(ida)):
            maxAtual = ida[i] = max(maxAtual, heights[i-1])

        volta = [0]*len(heights)

        maxAtual = 0
        for i in range(len(ida)-2, -1, -1):
            maxAtual = volta[i] = max(maxAtual, heights[i+1])

        vals = [max(min(ida[i], volta[i]) - heights[i] , 0) for i in range(len(ida))]
        maxWater = sum(vals)

        # print(ida)
        # print(volta)
        # print(vals)
        return maxWater
            