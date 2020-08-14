//Problem: https://leetcode.com/problems/binary-search/
//solution: https://labuladong.gitbook.io/algo/suan-fa-si-wei-xi-lie/er-fen-cha-zhao-xiang-ji

//solution1:
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res_index = -1;
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (target == nums[mid]) {
                res_index = mid;
                break;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = left + 1;
            }
        }
        return res_index;
    }
};
