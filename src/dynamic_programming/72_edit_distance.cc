//Problem: https://leetcode.com/problems/edit-distance/
//solution: https://labuladong.gitbook.io/algo/dong-tai-gui-hua-xi-lie/bian-ji-ju-li

//solution1: recursive
class Solution {
public:
    int minDistance(string word1, string word2) {
        return min_distance(word1, word1.length() - 1, word2, word2.length() - 1);
    }
    
private:
    int min_distance(const string &word1, int index1, 
                     const string &word2, int index2)
    {
        int min_dis = 0;
        if (-1 == index1) {
            min_dis = index2 + 1;
        } else if (-1 == index2) {
            min_dis = index1 + 1;
        } else if (word1[index1] == word2[index2]){
            min_dis = min_distance(word1, index1 - 1, word2, index2 - 1);
        } else {
            min_dis = min(min_distance(word1, index1, word2, index2 - 1) + 1,
                          min_distance(word1, index1 - 1, word2, index2) + 1);
            min_dis = min(min_distance(word1, index1 - 1, word2, index2 - 1) + 1,
                          min_dis);
        }
        return min_dis;
    }
};

//solution2: dp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int word1_size = word1.length();
        int word2_size = word2.length();
        vector<vector<int>> dp(word1_size + 1, vector<int>(word2_size + 1, 0));
        int tmp_min_dis = 0;
        
        for (int i = 1; i <= word1_size; ++i) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= word2_size; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= word1_size; ++i) {
            for (int j = 1; j <= word2_size; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    tmp_min_dis = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                    tmp_min_dis = min(dp[i - 1][j - 1] + 1, tmp_min_dis);
                    dp[i][j] = tmp_min_dis;
                }
            }
        }
        
        return dp[word1_size][word2_size];
    }
    
};
