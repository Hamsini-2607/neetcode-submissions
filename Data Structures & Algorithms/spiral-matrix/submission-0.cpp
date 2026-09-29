class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int srow = 0;
        int erow = matrix.size() - 1;
        int scol = 0;
        int ecol = matrix[0].size() - 1;
        while (srow <= erow && scol <= ecol) {
            for (int j = scol; j <= ecol; j++) {
                ans.push_back(matrix[srow][j]);
            }
            srow++;
            for (int i = srow; i <= erow; i++) {
                ans.push_back(matrix[i][ecol]);
            }
            ecol--;
            if (srow <= erow) {
                for (int j = ecol; j >= scol; j--) {
                    ans.push_back(matrix[erow][j]);
                }

                erow--;
            }
            if (scol <= ecol) {
                for (int j = erow; j >= srow; j--) {
                    ans.push_back(matrix[j][scol]);
                }
                scol++;
            }
        }

        return ans;
    }
};
