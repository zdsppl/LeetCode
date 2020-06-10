//Problem: https://leetcode.com/explore/learn/card/fun-with-arrays/527/searching-for-items-in-an-array/3250/

//solution1: time complexity: O(n)  space complexity: O(n)
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        bool ret = false;
        std::map<int, int> index_map;
        for (int i = 0; i < arr.size(); ++i) {
            index_map[arr[i]] = i;
        }
        for (int i = 0; i < arr.size(); ++i) {
            auto iter = index_map.find(2 * arr[i]);
            if (index_map.end() != iter && i != iter->second) {
                ret = true;
                break;
            }
        }
        return ret;
    }
};
