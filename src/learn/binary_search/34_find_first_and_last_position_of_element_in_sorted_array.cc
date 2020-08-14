//Problem: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
//solution: https://labuladong.gitbook.io/algo/suan-fa-si-wei-xi-lie/er-fen-cha-zhao-xiang-jie

//solution:
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int low_bound = 0;
        int upper_bound = 0;
        
        low_bound = find_low_bound(nums, target);
        res.push_back(low_bound);
        if (-1 == low_bound) {
            res.push_back(-1);
        } else {
            upper_bound = find_upper_bound(nums, target);
            res.push_back(upper_bound);
        }
        return res;
    }
    
private:
    int find_low_bound(const vector<int> &nums, const int target)
    {
        int low_bound = -1;
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (target == nums[mid]) {
                right = mid - 1;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else if (target < nums[mid]) {
                right = mid - 1;
            }
        }
     
        //if left >= nums.size(), all element in nums less than target
        //if target != nums[left], the target not exist or all element in nums more than target(this situation, right < 0)   
        if (left >= nums.size() || target != nums[left]) {
            //all num in nums more than target or target not exist
        } else {
            low_bound = left;
        }
        
        return low_bound;
    }
    
    int find_upper_bound(const vector<int> &nums, const int target)
    {
        int upper_bound = -1;
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (target == nums[mid]) {
                left = mid + 1;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else if (target < nums[mid]) {
                right = mid - 1;
            }
        }
        //if right < 0, all element in nums more than target
        //if target != nums[right], the target not exist or all element in nums less than target(this situation, left >= nums.size())
        if (right < 0 || target != nums[right]) {
            //all num in nums less than target or target not exist
        } else {
            upper_bound = right;
        }
        
        return upper_bound;
    }
};
