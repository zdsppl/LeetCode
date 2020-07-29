//Problem: https://leetcode.com/problems/longest-palindromic-subsequence/
//solution: https://mp.weixin.qq.com/s/zNai1pzXHeB2tQE6AdOXTA

//solution1:
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int max_palindrome_len = 0;
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        
        for (int i = len - 1; i >= 0; --i) {
            for (int j = i + 1; j < len; ++j) {
                if (s[i] == s[j]) {
		    //first palindrome subsequence may been 3, like "aba"
                    if ((i + 1 == j - 1) || ((j > i + 2) && !dp[i+1][j-1])) {
                        dp[i][j] = 3;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
                
                if (dp[i][j] > max_palindrome_len) {
                    max_palindrome_len = dp[i][j];
                }
            }
        }
        
        max_palindrome_len = max(max_palindrome_len, 1);
        
        return max_palindrome_len;
    }
};

//solution2:
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int max_palindrome_len = 0;
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len, 0));
  
	//init the dp[i][i] = 1, need not deal the (i + 1) = (j - 1) case     
        for (int i = 0; i < len; ++i) {
            dp[i][i] = 1;
        }
        for (int i = len - 1; i >= 0; --i) {
            for (int j = i + 1; j < len; ++j) {
                if (s[i] == s[j]) {
                    if ((j > i + 2) && !dp[i+1][j-1]) {
                        dp[i][j] = 3;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
                
                if (dp[i][j] > max_palindrome_len) {
                    max_palindrome_len = dp[i][j];
                }
            }
        }
        
        max_palindrome_len = max(max_palindrome_len, 1);
        
        return max_palindrome_len;
    }
};
