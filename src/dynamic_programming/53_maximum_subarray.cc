//Problem: https://leetcode.com/problems/maximum-subarray/

//solution1: time complexity: O(n)   space complexity: O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp_arr(size, 0);
        dp_arr[0] = nums[0];
        int max_num = nums[0];
        
        for (int i = 1; i < size; ++i) {
            dp_arr[i] = max(nums[i], nums[i] + dp_arr[i-1]);
        }
        
        for (int i = 0; i < size; ++i) {
            if (dp_arr[i] > max_num) {
                max_num = dp_arr[i];
            }
        }
        
        return max_num;
    }
};

//solution2: time complexity: O(n)  space complexity: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int prev_dp = nums[0];
        int curr_dp = 0;
        int max_num = nums[0];
        
        for (int i = 1; i < size; ++i) {
            curr_dp = max(nums[i], nums[i] + prev_dp);
            prev_dp = curr_dp;
            max_num = max(max_num, curr_dp);
        }
        
        return max_num;
    }
};
