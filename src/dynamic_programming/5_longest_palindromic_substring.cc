//Problem: https://leetcode.com/problems/longest-palindromic-substring/
//solution: https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484471&idx=1&sn=7c26d04a1f035770920d31377a1ebd42&chksm=9bd7fa3faca07329189e9e8b51e1a665166946b66b8e8978299ba96d5f2c0d3eafa7db08b681&scene=21#wechat_redirect

//solution1: time complexity: O(n2)  space complexity: O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        string max_palindrome_str;
        string curr_palindrome_str;
        for (int i = 0; i < s.length(); ++i) {
            curr_palindrome_str = palindrome_str(s, i, i);
            if (curr_palindrome_str.length() > max_palindrome_str.length()) {
                max_palindrome_str = curr_palindrome_str;
            }
            curr_palindrome_str = palindrome_str(s, i, i + 1);
            if (curr_palindrome_str.length() > max_palindrome_str.length()) {
                max_palindrome_str = curr_palindrome_str;
            }
        }
        return max_palindrome_str;
    }
private:
    string palindrome_str(const string &str, int left, int right)
    {
        while (left >= 0 && right < str.size() && str[left] == str[right]) {
            --left;
            ++right;
        }
        return str.substr(left + 1, right - left - 1);
    }
};

solution2: dp.  time complexity: O(n2)   space complexity: O(n2)
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        int start_pos = 0;
        int end_pos = 0;
        
        for (int i = len - 1; i >= 0; --i) {
            for (int j = i + 1; j < len; ++j) {
                if (s[i] == s[j]) {
                    if (j - i + 1 <= 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
            }
        }
        
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                if (dp[i][j] && ((j - i) > (end_pos - start_pos))) {
                    start_pos = i;
                    end_pos = j;
                }
            }
        }
        return s.substr(start_pos, end_pos - start_pos + 1);
    }
};
