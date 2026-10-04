class Solution {
public:
    unordered_map<int, int> dp;
    int climbStairs(int n) {
        if(n<=2) return n;
        if (dp.count(n)) return dp[n];

        return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};
