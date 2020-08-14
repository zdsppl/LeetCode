//Problem: https://leetcode.com/problems/combinations/
//solution: https://mp.weixin.qq.com/s/qT6WgR6Qwn7ayZkI3AineA

//solution: backtrack
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> track;
        vector<int> nums(n);
        for (int i = 1; i <= n; ++i) {
            nums[i - 1] = i;
        }
        backtrack(nums, 0, k, track, res);
        return res;
    }
    
private:
    void backtrack(const vector<int> &nums, int start, int size,
                   vector<int> &track, vector<vector<int>> &res)
    {
        if (size == track.size()) {
            res.push_back(track);
        } else {
            for (int i = start; i < nums.size(); ++i) {
                track.push_back(nums[i]);
                backtrack(nums, i + 1, size, track, res);
                track.pop_back();
            }
        }
    }
};
