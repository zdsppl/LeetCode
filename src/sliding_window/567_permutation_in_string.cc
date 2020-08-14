//Problem: https://leetcode.com/problems/permutation-in-string/
//solution1: https://mp.weixin.qq.com/s/ioKXTMZufDECBUwRRp3zaA

//solution1: sliding window
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        bool found = false;
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        int satisfy = 0;
        int left = 0;
        int right = 0;
        int tmp_left_char = '0';
        int tmp_right_char = '0';
        int window_start = 0;
        int min_window_size = INT_MAX;
        
        for (int i = 0; i < s1.size(); ++i) {
            need[s1[i]]++;
        }
        
        while (!found && right < s2.size()) {
            tmp_right_char = s2[right++];
            if (need.count(tmp_right_char)) {
                window[tmp_right_char]++;
                if (window[tmp_right_char] == need[tmp_right_char]) {
                    ++satisfy;
                }
            }
            
            while (satisfy == need.size()) {
                if (right - left < min_window_size) {
                    window_start = left;
                    min_window_size = right - left;
		    //提前退出
                    if (min_window_size == s1.length()) {
                        found = true;
                        break;
                    }
                }
                tmp_left_char = s2[left++];
                if (need.count(tmp_left_char)) {
                    if (window[tmp_left_char] == need[tmp_left_char]) {
                        --satisfy;
                    }
                    window[tmp_left_char]--;
                }
            }
        }
        return found;
    }
};
