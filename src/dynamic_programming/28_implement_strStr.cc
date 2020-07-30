//Problem: https://leetcode.com/problems/implement-strstr/
//solution: https://leetcode.com/problems/implement-strstr/

//solution1:
class Solution {
public:
    int strStr(string haystack, string needle) {
        int first_index = -1;
        
        if (needle.empty()) {
            first_index = 0;
        } else {
            int needle_size = needle.size();
            vector<int> next(needle_size, 0);
            int j = 0;
        
            build_next_arr(needle, next);
            for (int i = 0; i < haystack.size();) {
                if (-1 == j || haystack[i] == needle[j]) {
		    //only when match ,progress the i
                    ++j;
                    ++i;
                } else {
                    j = next[j];
                }
                if (needle_size == j) {
                    first_index = i - needle_size;
                    break;
                }
            }
        }
        
        return first_index;
    }
    
private:
    void build_next_arr(const string &needle, vector<int> &next)
    {
        int size = next.size();
        int index = 0;
        int next_index = -1;
        next[0] = -1;
  	//here index should less than size - 1, because line 45
        while (index < size - 1) {
            if (-1 == next_index || needle[next_index] == needle[index]) {
                ++index;
                ++next_index;
                next[index] = next_index;
            } else {
                next_index = next[next_index];
            }
        }
    }
};
