//Problem: https://leetcode.com/explore/learn/card/linked-list/214/two-pointer-technique/1212/

//solution 1: time complexity: O(n)  space complexity: O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        bool has_cycle = false;
        if (nullptr != head) {
            ListNode *slow_ptr = head;
            ListNode *fast_ptr = head;
            
            if (head == head->next) {
                has_cycle = true;
            } else {
                if (nullptr == fast_ptr->next) {
                    //no cycle
                    fast_ptr = fast_ptr->next;
                } else {
                    fast_ptr = fast_ptr->next->next;
                }
                while (nullptr != slow_ptr && nullptr != fast_ptr) {
                    if (slow_ptr == fast_ptr) {
                        has_cycle = true;
                        break;
                    } else {
                        if (nullptr != fast_ptr->next) {
                            fast_ptr = fast_ptr->next->next;
                        } else {
                            fast_ptr = fast_ptr->next;
                        }
                        if (nullptr != slow_ptr) {
                            slow_ptr = slow_ptr->next;
                        }
                    }
                }
            }
        }       
        return has_cycle;
    }
};

//solution2: time complexity: O(n)  space complexity: O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        
        auto p{head}, q{head->next};
        while (q && q->next) {
            if (q == p) return true;  
            p = p->next;   
            q = q->next->next;
        }
        return false;
    }
};
