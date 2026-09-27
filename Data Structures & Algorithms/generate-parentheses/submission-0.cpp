class Solution {
   public:
    void solve(int opencount, int closecount, string& curr, vector<string>& ans, int n) {
        if (opencount == n && closecount == n) {
            ans.push_back(curr);
            return;
        }
        if (opencount < n) {
            curr.push_back('(');
            solve(opencount + 1, closecount, curr, ans, n);
            curr.pop_back();
        }
        if (closecount < opencount) {
            curr.push_back(')');
            solve(opencount, closecount + 1, curr, ans, n);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        vector<string> ans;
        solve(0, 0, curr, ans, n);
        return ans;
    }
};
