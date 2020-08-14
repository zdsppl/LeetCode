//Problem: https://leetcode.com/problems/find-all-anagrams-in-a-string/
//solution: https://mp.weixin.qq.com/s/ioKXTMZufDECBUwRRp3zaA

//solution: sliding window
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> target_chars;
        unordered_map<char, int> window_chars;
        int left = 0;
        int right = 0;
        char tmp_left_char = '0';
        char tmp_right_char = '0';
        int satisfy_char_num = 0;
        
        for (int i = 0; i < p.length(); ++i) {
            target_chars[p[i]]++;
        }
        
        while (right < s.size()) {
            tmp_right_char = s[right++];
            if (target_chars.count(tmp_right_char)) {
                window_chars[tmp_right_char]++;
                if (window_chars[tmp_right_char] == target_chars[tmp_right_char]) {
                    ++satisfy_char_num;
                }
            }
            
            while (satisfy_char_num == target_chars.size()) {
                if (p.length() == (right - left)) {
                    res.push_back(left);
                }
                tmp_left_char = s[left++];
                if (target_chars.count(tmp_left_char)) {
                    if (window_chars[tmp_left_char] == target_chars[tmp_left_char]) {
                        --satisfy_char_num;
                    }
                    window_chars[tmp_left_char]--;
                }
            }
        }
        
        return res;
    }
};
