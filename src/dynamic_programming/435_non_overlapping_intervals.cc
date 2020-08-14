//Problem: https://leetcode.com/problems/non-overlapping-intervals/
//solution: https://labuladong.gitbook.io/algo/dong-tai-gui-hua-xi-lie/tan-xin-suan-fa-zhi-qu-jian-tiao-du-wen-ti

//solution1: greedy algorithm
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int erase_count = 0;
        
        if (intervals.size() > 1) {
            VectorCompare vector_compare;
            std::sort(intervals.begin(), intervals.end(), vector_compare);
            vector<int> curr_interval;
            vector<int> tmp_interval;
        
            curr_interval = intervals[0];
            for (int i = 1; i < intervals.size(); ++i) {
                tmp_interval = intervals[i];
                if (tmp_interval[0] < curr_interval[1]) {
                    ++erase_count;
                } else {
                    curr_interval = tmp_interval;
                }
            }
        }
        
        return erase_count;
    }
    
private:
    class VectorCompare {
    public:
      bool operator()(const vector<int> &left, const vector<int> &right)
      {
          return left[1] <= right[1];
      }
    };
};
