//Problem: https://leetcode.com/problems/sudoku-solver/
//solution: https://labuladong.gitbook.io/algo/suan-fa-si-wei-xi-lie/sudoku

//solution: backtrack
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }
private:
    bool backtrack(vector<vector<char>> &board, int row, int col)
    {
        bool res = false;
        int row_max = 9;
        int col_max = 9;
        if (col_max == col) {
            res = backtrack(board, row + 1, 0);
        } else if (row_max == row) {
            res = true;
        } else if ('.' != board[row][col]) {
            res = backtrack(board, row, col + 1);
        } else {
            for (char ch = '1'; ch <= '9'; ++ch) {
                if (!is_valid(board, row, col, ch)) {
                    continue;
                }
                board[row][col] = ch;
                if (!(res = backtrack(board, row, col + 1))) {
                    board[row][col] = '.';
                }
            }
        }
        return res;
    }
    
    bool is_valid(const vector<vector<char>> &board, int row, int col, char ch)
    {
        bool valid = true;
        for (int i = 0; i < 9; ++i) {
            if (ch == board[row][i]) {
                valid = false;
                break;
            }
            
            if (ch == board[i][col]) {
                valid = false;
                break;
            }
            
            if (ch == board[(row/3) * 3 + i / 3][(col/3) * 3 + i % 3]) {
                valid = false;
                break;
            }
        }
        return valid;
    }
};
