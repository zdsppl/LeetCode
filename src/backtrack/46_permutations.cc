//Problem: https://leetcode.com/problems/permutations/
//solution: https://labuladong.gitbook.io/algo/suan-fa-si-wei-xi-lie/hui-su-suan-fa-xiang-jie-xiu-ding-ban

//solution: backtrack
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> all_permutation;
        vector<int> curr_permutation;
        permute_internal(nums, curr_permutation, all_permutation);
        return all_permutation;
    }
    
private:
    void permute_internal(const vector<int> &nums,
                          vector<int> &permutation,
                          vector<vector<int>> &all_permutation)
    {
        if (nums.size() == permutation.size()) {
            all_permutation.push_back(permutation);
        } else {
            for (int i = 0; i < nums.size(); ++i) {
                if (vector_contain(permutation, nums[i])) {
                    continue;
                } else {
                    permutation.push_back(nums[i]);
                    permute_internal(nums, permutation, all_permutation);
                    permutation.pop_back();
                }
            }
        }
    }
    
    bool vector_contain(const vector<int> &vec, const int target)
    {
        bool contain = false;
        for (int i = 0; i < vec.size(); ++i) {
            if (target == vec[i]) {
                contain = true;
                break;
            }
        }
        return contain;
    }
};
