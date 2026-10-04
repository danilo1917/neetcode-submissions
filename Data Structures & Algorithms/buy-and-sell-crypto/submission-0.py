class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # dp[i] = max(dp[i-1], pAtual - preçoPago)

        precoPago = 10000000000
        maxVal = 0
        for i in range(len(prices)):
            if prices[i] - precoPago > maxVal:
                maxVal = prices[i] - precoPago
            else:
                if (prices[i] < precoPago):
                    precoPago = prices[i]


        return maxVal
