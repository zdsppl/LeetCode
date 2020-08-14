//Problem: https://leetcode.com/problems/subsets/
//solution: https://mp.weixin.qq.com/s/qT6WgR6Qwn7ayZkI3AineA

//solution: backtrack
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sub_sets;
        vector<int> track;
        backtrack(nums, 0, track, sub_sets);
        return sub_sets;
    }
private:
    void backtrack(const vector<int> &nums, int start,
                   vector<int> &track, vector<vector<int>> &sub_sets)
    {
        sub_sets.push_back(track);
        if (nums.size() == start) {
            //do nothing
        } else {
            for (int i = start; i < nums.size(); ++i) {
                track.push_back(nums[i]);
                backtrack(nums, i + 1, track, sub_sets);
                track.pop_back();
            }
        }
    }
};
