class Solution {
   public:
    void solve(vector<int>& curr, vector<vector<int>>& ans, int idx, vector<int>& nums) {
        if (idx == nums.size()) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        solve(curr, ans, idx + 1, nums);
        curr.pop_back();
        solve(curr, ans, idx+1, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        int idx;
        solve(curr, ans, 0, nums);
        return ans;
    }
};
