class Solution {
public: 
    vector<bool> dp;
    bool canJump(vector<int>& nums, int pos) {
        if (pos < 0) return false;
        if (dp[pos]) return true;
        
        for (int i=0; i<pos; i++){
            dp[pos] = dp[pos] || nums[i] >= pos - i && canJump(nums, i);
        }

        return dp[pos];
    }

    bool canJump(vector<int>& nums) {
        dp.resize(nums.size());
        dp[0] = true;

        return canJump(nums, nums.size()-1);
    }
};
