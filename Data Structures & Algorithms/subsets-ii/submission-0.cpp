class Solution {
   public:
    void solve(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& ans) {
        ans.push_back(current);

        for (int i = start; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] && i > start) {
                continue;
            }

            current.push_back(nums[i]);
            solve(i + 1, nums, current, ans);
            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        solve(0, nums, current, ans);
        return ans;
    }
};

/*What happens if you use nums[i] == nums[i + 1] (Broken)
If you check i + 1, you flip the logic in two destructive ways:

It blocks legitimate valid subsets:
If nums = [1, 2, 2], when i = 1 (the first 2), looking ahead at i + 1 sees the second 2. It will
skip the first 2 immediately! This prevents you from ever forming the valid subset [1, 2, 2],
because you can never pick two 2s in a row.

It leads to out-of-bounds memory errors:
When i reaches the last element of the array (i = nums.size() - 1), checking nums[i + 1] looks
beyond the end of the vector, causing undefined behavior or a crash.*/