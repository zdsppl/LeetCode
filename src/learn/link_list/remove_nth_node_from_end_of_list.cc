//Problem: https://leetcode.com/explore/learn/card/linked-list/214/two-pointer-technique/1296/

//solution1: time complexity: O(n)  space complexity: O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *new_head = nullptr;
        if (nullptr == head) {
            //empty list, do nothing
        } else {
            int index = 1;
            ListNode *target_node = head;
            ListNode *cursor_node = head;
            ListNode *prev_node = head;
            while (cursor_node) {
                if (index > n) {
                    prev_node = target_node;
                    target_node = target_node->next;
                }
                cursor_node = cursor_node->next;
                ++index;
            }
            if (head == target_node) {
                head = head->next;
            } else {
                prev_node->next = target_node->next;
            }
        }
        return head;
        
    }
};
