class Solution {
   public:
    void solve(vector<string>& ans, string& curr, string digits, int idx) {
        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string letters = mapping[digits[idx] - '0'];
        for (char ch : letters) {
            curr.push_back(ch);
            solve(ans, curr, digits, idx + 1);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        static const vector<string> mapping = {"",    "",    "abc",  "def", "ghi",
                                                   "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> ans;
        string curr;
        solve(ans, curr, digits, 0);
        return ans;
    }
};
