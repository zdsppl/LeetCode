//Problem: https://leetcode.com/explore/learn/card/fun-with-arrays/525/inserting-items-into-an-array/3253/

//solution1: time complexity: O(n)  space complexity: O(n)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> merged_vector;
        int nums1_index = 0;
        int nums2_index = 0;
        while (true) {
            //defense m or n is zero, so the overflow condition should at front
            if (nums1_index >= m) {
                for (; nums2_index < n; ++nums2_index) {
                    merged_vector.push_back(nums2[nums2_index]);
                }
                break;
            }
            if (nums2_index >= n) {
                for (; nums1_index < m; ++nums1_index) {
                    merged_vector.push_back(nums1[nums1_index]);
                }
                break;
            }
            if (nums1[nums1_index] < nums2[nums2_index]) {
                merged_vector.push_back(nums1[nums1_index]);
                ++nums1_index;
            } else {
                merged_vector.push_back(nums2[nums2_index]);
                ++nums2_index;
            }
        }
        nums1 = merged_vector;
    }
};
