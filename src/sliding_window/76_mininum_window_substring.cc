//Problem: https://leetcode.com/problems/minimum-window-substring/
//solution: https://mp.weixin.qq.com/s/ioKXTMZufDECBUwRRp3zaA

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        int satisfy = 0;
        int left = 0;
        int right = 0;
        char tmp_right_char = '0';
        char tmp_left_char = '0';
        int min_window_size = s.size() + 1;
        int window_start = 0;
        
        for (int i = 0; i < t.length(); ++i) {
            need[t[i]]++;
        }
        
        while (right < s.size()) {
            tmp_right_char = s[right++];
	    //注意这里只能用count，不能need[tmp_right_char],因为这样相当于插入了tmp_right_char, 不符合预期
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
                }
                tmp_left_char = s[left++];
	    	//注意这里只能用count，不能need[tmp_left_char],因为这样相当于插入了tmp_left_char, 不符合预期
                if (need.count(tmp_left_char)) {
                    if (window[tmp_left_char] == need[tmp_left_char]) {
                        --satisfy;
                    }
                    window[tmp_left_char]--;
                }
            }
        }
        return min_window_size > s.size() ? "" : s.substr(window_start, min_window_size);
    }
};
