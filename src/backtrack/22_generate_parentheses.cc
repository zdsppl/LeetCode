//Problem: https://leetcode.com/problems/generate-parentheses/
//solution: https://labuladong.gitbook.io/algo/suan-fa-si-wei-xi-lie/he-fa-kuo-hao-sheng-cheng

//solution: backtrack
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int total_length = 2 * n;
        int curr_length = 0;
        string str(total_length, '\0');
        backtrack(total_length, str, curr_length, res);
        return res;
    }
private:
    void backtrack(const int total_length,
                   string &str, int curr_length,
                   vector<string> &res)
    {
        if (total_length == curr_length) {
            res.push_back(str);
        } else {
            if (is_valid(total_length, str, curr_length, '(')) {
                str[curr_length] = '(';
                backtrack(total_length, str, curr_length + 1, res);
                str[curr_length] = '\0';
            }
            
            if (is_valid(total_length, str, curr_length, ')')) {
                str[curr_length] = ')';
                backtrack(total_length, str, curr_length + 1, res);
                str[curr_length] = '\0';
            }
        }
    }
    
    bool is_valid(const int total_length,
                  const string &str, int curr_length,
                  const char ch)
    {
        bool valid = true;
        int left_parentheses = '(' == ch ? 1 : 0;
        int right_parentheses = ')' == ch ? 1 : 0;
        
        for (int i = 0; i < curr_length; ++i) {
            if ('(' == str[i]) {
                ++left_parentheses;
            } else if (')' == str[i]) {
                ++right_parentheses;
            }
        }
        
        if (total_length == curr_length + 1) {
            if (left_parentheses != right_parentheses) {
                valid = false;
            }
        } else {
            if (left_parentheses < right_parentheses
                || left_parentheses > total_length / 2
                || right_parentheses > total_length / 2) {
                valid = false;
            }
        }
        
        return valid;
    }
};
