class Solution {
   public:
    bool isvalid(string part) {
        if (part.empty() || part.size() > 3) {
            return false;
        }
        if (part.size() > 1 && part[0] == '0') {
            return false;
        }
        int num = stoi(part);
        return num <= 255;
    }
    void solve(vector<string>& parts, string s, int start, vector<string>& ans) {
        if (parts.size() == 4) {
            if (start == s.size()) {
                string ip = parts[0] + "." + parts[1] + "." + parts[2] + "." + parts[3];
                ans.push_back(ip);
            
            }
            return;
        }
        for (int len = 1; len <= 3 && len + start <= s.size(); len++) {
            string part = s.substr(start, len);
            if (isvalid(part)) {
                parts.push_back(part);
                solve(parts, s, start + len, ans);
                parts.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> parts;
        vector<string> ans;
        solve(parts,s,0,ans);
        return ans;
    }
};