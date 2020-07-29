//Problem: https://leetcode.com/problems/longest-common-subsequence/
//solution: https://labuladong.gitbook.io/algo/dong-tai-gui-hua-xi-lie/zui-chang-gong-gong-zi-xu-lie

//solution1: recursive
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        return dp(text1, text1.length() - 1, text2, text2.length() - 1);
    }
private:
    int dp(const string &text1, int index1, const string &text2, int index2)
    {
        int res = 0;
        if (index1 < 0 || index2 < 0) {
            return res;
        } else {
            if (text1[index1] == text2[index2]) {
                res = dp(text1, index1 - 1, text2, index2 - 1) + 1;
            } else {
                res = max(dp(text1, index1 - 1, text2, index2),
                          dp(text1, index1, text2, index2 - 1));
            }
        }
        return res;
    }
};

//solution: dp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int text1_size = text1.length();
        int text2_size = text2.length();
        vector<vector<int>> dp(text1_size + 1, vector<int>(text2_size + 1, 0));
        
        for (int i = 1; i <= text1_size; ++i) {
            for (int j = 1; j <= text2_size; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[text1_size][text2_size];
    }
};
