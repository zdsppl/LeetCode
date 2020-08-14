//Problem: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
//solution: https://labuladong.gitbook.io/algo/dong-tai-gui-hua-xi-lie/tan-xin-suan-fa-zhi-qu-jian-tiao-du-wen-ti

//solution1: greedy algorithm
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int points_size = points.size();
        int min_arrow_shot = 0;
        if (points_size > 0) {
            min_arrow_shot = 1;
            vector<int> curr_point;
            vector<int> tmp_point;
            PointCompare point_compare;
            std::sort(points.begin(), points.end(), point_compare);
            
            curr_point = points[0];
            for (int i = 1; i < points.size(); ++i) {
                tmp_point = points[i];
                if (curr_point[1] < tmp_point[0]) {
                    ++min_arrow_shot;
                    curr_point = tmp_point;
                }
            }
        }
        
        return min_arrow_shot;
    }
    
private:
    class PointCompare {
      public:
        bool operator()(const vector<int> &left, const vector<int> &right)
        {
            return left[1] <= right[1];
        }
    };
};
