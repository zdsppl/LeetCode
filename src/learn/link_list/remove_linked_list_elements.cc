//Problem: https://leetcode.com/explore/learn/card/linked-list/219/classic-problems/1207/

//solution: time complexity: O(n)  space complexity: O(1)
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *cursor_node = head;
        ListNode *prev_node = head;
        ListNode *new_head = head;
        while (nullptr != cursor_node) {
            if (val == cursor_node->val) {
                if (new_head == cursor_node) {
                    new_head = cursor_node->next;
                    prev_node = cursor_node->next;
                    cursor_node = cursor_node->next;
                } else {
                    prev_node->next = cursor_node->next;
                    cursor_node = cursor_node->next;
                }
            } else {
                prev_node = cursor_node;
                cursor_node = cursor_node->next;
            }
        }
        return new_head;
    }
};
