class Solution {
public:
    vector<vector<int>> sol;

    vector<int> curr;
    void combinationSu(vector<int>& nums, int target, int j = 0) {
        if (target == 0){
            sol.push_back(curr);
            return;
        }

        if (target < 0) return;

        for (int i= j; i< nums.size(); i++){
            curr.push_back(nums[i]);
            combinationSu(nums, target - nums[i], i);
            curr.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        combinationSu(nums, target);
        return sol;
    }
};
