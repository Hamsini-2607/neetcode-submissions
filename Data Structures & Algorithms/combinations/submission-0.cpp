class Solution {
   public:
    void solve(vector<vector<int>>& ans, vector<int>& current, int k, int num,int n) {
        if (current.size() == k) {
            ans.push_back(current);
            return;
        }
        for (int i = num; i <= n; i++) {
            current.push_back(i);
            solve(ans, current, k, i + 1,n);
            current.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> current;
        solve(ans,current,k,1,n);
        return ans;
    }
};