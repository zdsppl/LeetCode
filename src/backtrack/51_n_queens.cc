//Problem: https://leetcode.com/problems/n-queens/
//solution: https://labuladong.gitbook.io/algo/suan-fa-si-wei-xi-lie/hui-su-suan-fa-xiang-jie-xiu-ding-ban

//solution: backtrack
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> all_solution;
        vector<string> curr_solution(n, string(n, '.'));
        int row = 0;
        backtrack(curr_solution, row, all_solution);
        return all_solution;
    }
private:
    void backtrack(vector<string> &curr_solution,
                   int row,
                   vector<vector<string>> &all_solution)
    {
        if (curr_solution.size() == row) {
            all_solution.push_back(curr_solution);
        } else {
            for (int col = 0; col < curr_solution.size(); ++col) {
                if (!is_valid(curr_solution, row, col)) {
                    continue;
                }
                curr_solution[row][col] = 'Q';
                backtrack(curr_solution, row + 1, all_solution);
                curr_solution[row][col] = '.';
            }
        }
    }
    
    bool is_valid(const vector<string> &curr_solution, int row, int col)
    {
        bool valid = true;
        
        for (int i = 0; i < row; ++ i) {
            if ('Q' == curr_solution[i][col]) {
                valid = false;
                break;
            }
        }
        
        if (valid) {
            for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
                if ('Q' == curr_solution[i][j]) {
                    valid = false;
                    break;
                }
            }
        }
        
        if (valid) {
            for (int i = row - 1, j = col + 1; i >= 0 && j < curr_solution.size();
                 --i, ++j) {
                if ('Q' == curr_solution[i][j]) {
                    valid = false;
                    break;
                }
            }
        }
        
        return valid;
    }
};
