class Solution {
   public:
    void solve(vector<vector<int>>& ans, vector<int>& current, vector<int>& used,
               vector<int>& nums) {
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == 1) {
                continue;
            }
            current.push_back(nums[i]);
            used[i] = 1;
            solve(ans, current, used, nums);
            current.pop_back();
            used[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        vector<int> used(nums.size(),0);
        solve(ans, current, used, nums);
        return ans;
    }
};
