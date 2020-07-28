//Problem: https://leetcode.com/explore/learn/card/queue-stack/231/practical-application-queue/1375/

//solution1: bfs
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadends_set(deadends.begin(), deadends.end());
        unordered_set<string> visited_set;
        bool success_open = false;
        int step = 0;
        int size = 0;
        queue<string> string_queue;
        string curr_string;
        string tmp_string1;
        string tmp_string2;
        string_queue.push("0000");
        
        if (deadends_set.count("0000")) {
            //the lock is dead lock, do nothing
        } else {
            while (!success_open && !string_queue.empty()) {
                ++step;
                size = string_queue.size();
                for (int i = 0; i < size; ++i) {
                    curr_string = string_queue.front();
                    string_queue.pop();
                    for (int i = 0; i < 4; ++i) {
                        tmp_string1 = curr_string;
                        tmp_string1[i] = inc_one(tmp_string1[i]);
                        tmp_string2 = curr_string;
                        tmp_string2[i] = dec_one(tmp_string2[i]);
                        if (target == tmp_string1 || target == tmp_string2) {
                            //success open the lock
                            success_open = true;
                            break;
                        } else {
                            if (!visited_set.count(tmp_string1) && !deadends_set.count(tmp_string1)) {
                                string_queue.push(tmp_string1);
                            }
                            if (!visited_set.count(tmp_string2) && !deadends_set.count(tmp_string2)) {
                                string_queue.push(tmp_string2);
                            }
                            visited_set.emplace(tmp_string1);
                            visited_set.emplace(tmp_string2);
                        }   
                    }
                }
            }
        }
        step = success_open ? step : -1;
        return step;
    }
    
private:
    inline char inc_one(char origin)
    {
        char res = origin;
        if ('9' == origin) {
            res = '0';
        } else {
            res = origin - '0' + 1 + '0';
        }
        return res;
    }
    inline char dec_one(char origin)
    {
        char res = origin;
        if ('0' == origin) {
            res = '9';
        } else {
            res = origin - '0' - 1 + '0';
        }
        return res;
    }
};
