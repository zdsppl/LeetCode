//Problem: https://leetcode.com/problems/coin-change-2/
//solution: https://labuladong.gitbook.io/algo/dong-tai-gui-hua-xi-lie/bei-bao-ling-qian

//solution1: time complexity: O(n2)  space complexity: O(n2)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int res = 0;
        int size = coins.size();
        if (amount < 0) {
            //one is least
        } else {
            vector<vector<int>> dp(size + 1, vector<int>(amount + 1, 0));
            for (int i = 0; i < size + 1; ++i) {
                dp[i][0] = 1;
            }
            for (int i = 1; i <= size; ++i ) {
                for (int j = 1; j <= amount; ++j) {
                    if (coins[i - 1] > j) {
                        dp[i][j] = dp[i-1][j];
                    } else {
			//注意这里是求和，跟之前的求max不一样，并且注意是dp[i][j - coins[i - 1]], not dp[i - 1][j - coins[i - 1]]
                        dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                    }
                }
            }
            res = dp[size][amount];
        }
        return res;
    }
                                   
};

//solution2: time complexity: O(n2)   space complexity: O(n)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int res = 0;
        int size = coins.size();
        if (amount < 0) {
            //one is least
        } else {
            //vector<vector<int>> dp(size + 1, vector<int>(amount + 1, 0));
            vector<int> dp(amount + 1, 0);
            dp[0] = 1;
            /*
            for (int i = 0; i < size + 1; ++i) {
                dp[i][0] = 1;
            }
            */
            for (int i = 1; i <= size; ++i ) {
                for (int j = 1; j <= amount; ++j) {
                    if (coins[i - 1] > j) {
                        //do nothing
                        //dp[j] = dp[j];
                    } else {
                        dp[j] = dp[j] + dp[j - coins[i - 1]];
                    }
                }
            }
            res = dp[amount];
        }
        return res;
    }
                                   
};
