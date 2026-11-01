class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // KAdane's algo

        int maxSum = INT_MIN;
        int curr = 0;
        for ( auto v: nums){
            curr+=v;
            maxSum = max( maxSum, curr);
            if (curr < 0){
                curr = 0;
            }
        }

        return maxSum;
    }
};
