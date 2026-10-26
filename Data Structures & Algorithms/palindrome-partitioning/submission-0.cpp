class Solution {
   public:
    void solve(int start, vector<string>& curr, vector<vector<string>>& ans, string& s) {
        if (s.size() == start) {
            ans.push_back(curr);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            string part = s.substr(start, i - start + 1);
            if (ispalindrome(part)) {
                curr.push_back(part);
                solve(i + 1, curr, ans, s);
                curr.pop_back();
            }
        }
    }

    bool ispalindrome(string part) {
        int left = 0;
        int right = part.size() - 1;
        while (left < right) {
            if (part[left] != part[right]) {
                return false;
            }

            left++;
            right--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> ans;
        solve(0, curr, ans, s);
        return ans;
    }
};
