//Problem: https://leetcode.com/problems/partition-equal-subset-sum/
//solution: https://labuladong.gitbook.io/algo/dong-tai-gui-hua-xi-lie/bei-bao-zi-ji

//solution1: time complexity: O(n2)  space complexity: O(n2)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bool res = false;
        int sum = 0;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            sum += nums[i];
        }
        if (sum % 2 != 0) {
            //even sum, can't partition
        } else {
            sum = sum / 2;
            vector<vector<bool>> dp(size + 1, vector<bool>(sum + 1, false));
            for (int i = 0; i < size + 1; ++i) {
                dp[i][0] = true;
            }
            for (int i = 1; i <= size; ++i) {
                for (int j = 1; j <= sum; ++j) {
                    if (nums[i - 1] > j) {
                        //too big, can't put in
                    } else {
                        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                    }
                }
            }
            res = dp[size][sum];
        }
        return res;
    }
};

//solution2: time complexity: O(n2)   space complexity: O(n)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bool res = false;
        int sum = 0;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            sum += nums[i];
        }
        if (sum % 2 != 0) {
            //even sum, can't partition
        } else {
            sum = sum / 2;
            vector<bool> dp(sum + 1, false);
            dp[0] = true;
            for (int i = 1; i <= size; ++i) {
                for (int j = sum; j > 0; --j) {
                    if (nums[i - 1] > j) {
                        //too big, can't put in
                    } else {
                        dp[j] = dp[j] || dp[j - nums[i - 1]];
                    }
                }
            }
            res = dp[sum];
        }
        return res;
    }
};
