//Problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/
//solution: https://mp.weixin.qq.com/s/ioKXTMZufDECBUwRRp3zaA

//solution1:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        unordered_map<char, int> windows_chars;
        int left = 0;
        int right = 0;
        char tmp_left_char = '0';
        char tmp_right_char = '0';
        
        while (right < s.length()) {
            tmp_right_char = s[right++];
            if (!windows_chars.count(tmp_right_char)) {
                windows_chars[tmp_right_char]++;
                if (right - left > max_length) {
                    max_length = right - left;
                }
            } else {
                while (true) {
                    tmp_left_char = s[left++];
                    if (tmp_right_char == tmp_left_char) {
                        break;
                    } else {
                        windows_chars.erase(tmp_left_char);
                    }
                }
                
            }
        }
        return max_length;
    }
};

//solution2:
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> window;

    int left = 0, right = 0;
    int res = 0; // 记录结果
    while (right < s.size()) {
        char c = s[right];
        right++;
        // 进行窗口内数据的一系列更新
        window[c]++;
        // 判断左侧窗口是否要收缩
        while (window[c] > 1) {
            char d = s[left];
            left++;
            // 进行窗口内数据的一系列更新
            window[d]--;
        }
        // 在这里更新答案
        res = max(res, right - left);
    }
    return res;
}
