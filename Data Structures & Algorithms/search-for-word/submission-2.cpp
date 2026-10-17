class Solution {
   public:
    bool solve(int row, int col, int idx, string word, vector<vector<char>>& board) {
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) {
            return false;
        }
        if (word[idx] != board[row][col]) {
            return false;
        }
        if (idx == word.size() - 1) {
            return true;
        }
        char temp = board[row][col];
        board[row][col] = '#';
        bool found = solve(row, col + 1, idx + 1, word, board) ||
                     solve(row + 1, col, idx + 1,word, board) || solve(row, col - 1, idx + 1,word, board) ||
                     solve(row - 1, col, idx + 1,word, board);
        board[row][col] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i <row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == word[0]) {
                    if (solve(i, j, 0, word, board)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
