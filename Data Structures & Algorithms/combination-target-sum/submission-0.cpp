class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& current, int remaining, int idx, vector<int>& nums) {
        if (remaining == 0) {
            ans.push_back(current);
            return;
        }
        if (remaining < 0 || idx == nums.size()) {
            return;
        }

        // Option 1: Include nums[idx] (can reuse the same element, so index remains `idx`)
        current.push_back(nums[idx]);
        solve(ans, current, remaining - nums[idx], idx, nums);
        current.pop_back();

        // Option 2: Exclude nums[idx] (move to `idx + 1` WITHOUT subtracting from remaining)
        solve(ans, current, remaining, idx + 1, nums);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        solve(ans, current, target, 0, nums);
        return ans;
    }
};