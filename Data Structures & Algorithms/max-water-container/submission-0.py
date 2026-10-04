class Solution:
    def maxArea(self, heights: List[int]) -> int:
        # A intuicao é sempre mover o menor

        p1 = 0
        p2 = len(heights) -1
        maxA = 0
        while (p1 < p2):
            a = min(heights[p1], heights[p2])*(p2 - p1)
            maxA = max(maxA, a)
            if (heights[p1] <= heights[p2]):
                p1+=1
            else:
                p2-=1
        return maxA

