//Problem: https://leetcode.com/explore/learn/card/linked-list/213/conclusion/1295/

//solution: time complexity: O(n)   space complexitu: O(1)
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *origin_head = head;
        ListNode *origin_tail = head;
        ListNode *new_head = head;
        ListNode *new_tail = nullptr;
        int node_count = 1;
        int rotate_step = 0;
        if (nullptr == origin_head || nullptr == origin_head->next) {
            //empty list or only one node, do nothing
        } else {
            while (nullptr != origin_tail && nullptr != origin_tail->next) {
                origin_tail = origin_tail->next;
                ++node_count;
            }
            rotate_step = k % node_count;
            if (0 != rotate_step) {
                new_tail = origin_head;
                for (int i = 0; i < (node_count - rotate_step - 1); ++i) {
                    new_tail = new_tail->next;
                }
                new_head = new_tail->next;
                new_tail->next = nullptr;
                origin_tail->next = origin_head;    
            }
        }
        return new_head;
    }
};
