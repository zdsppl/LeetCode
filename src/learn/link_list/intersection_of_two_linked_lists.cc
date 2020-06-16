//Problem:https://leetcode.com/explore/learn/card/linked-list/214/two-pointer-technique/1215/

//solution: time complexity:O(n)   space complexity:O(1)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *node = nullptr;
        if (nullptr == headA || nullptr == headB) {
            //no intersection, do nothing
        } else {
            ListNode *A_tail = headA;
            while (nullptr != A_tail->next) {
                A_tail = A_tail->next;
            }
            A_tail->next = headA;
            node = detect_cycle(headB);
            A_tail->next = nullptr;
        }
        return node;
    }
    
private:
    //dectect the Linked list has cycle or not
    //if has cycle, return the first node of the cycle
    ListNode *detect_cycle(ListNode *head) {
        ListNode *first_node_of_cycle = nullptr;
        if (nullptr == head) {
            //no cycle, do nothing
        } else {
            bool has_cycle = false;
            ListNode *fast_ptr = head;
            ListNode *slow_ptr = head;
            while (fast_ptr && fast_ptr->next) {
                slow_ptr = slow_ptr->next;
                fast_ptr = fast_ptr->next->next;
                if (slow_ptr == fast_ptr) {
                    has_cycle = true;
                    break;
                }
            }
            
            if (has_cycle) {
                slow_ptr = head;
                while (slow_ptr != fast_ptr) {
                    slow_ptr = slow_ptr->next;
                    fast_ptr = fast_ptr->next;
                }
                first_node_of_cycle = slow_ptr;
            }
        }
        return first_node_of_cycle;
    }
    
};
