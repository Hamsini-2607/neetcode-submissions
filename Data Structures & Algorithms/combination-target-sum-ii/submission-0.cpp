class Solution {
   public:
    void solve(int start, vector<int>& curr, vector<vector<int>>& ans, int remaining,
               vector<int>& candidates) {
        if (remaining == 0) {
            ans.push_back(curr);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (remaining < candidates[i]) {
                break;
            }
            if (candidates[i] == candidates[i - 1] && i > start) {
                continue;
            }

            curr.push_back(candidates[i]);
            solve(i + 1, curr, ans, remaining - candidates[i], candidates);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        solve(0, curr, ans, target, candidates);
        return ans;
    }
};
