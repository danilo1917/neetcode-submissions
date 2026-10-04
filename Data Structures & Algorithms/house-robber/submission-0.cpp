class Solution {
public:
    unordered_map<int, int> dp;
    int rob(vector<int>& nums, int pos) {
        if (pos>=nums.size()) return 0;

        if (dp.count(pos)) return dp[pos];

        return dp[pos] = max(nums[pos] + rob(nums, pos +2), rob(nums, pos+1));
    }
    int rob(vector<int>& nums) {
        return rob(nums, 0);
    }
};
