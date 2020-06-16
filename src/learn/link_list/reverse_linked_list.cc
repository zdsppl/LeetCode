//Problem:https://leetcode.com/explore/learn/card/linked-list/219/classic-problems/1205/

//solution: time complexity: O(n)   space complexity: O(1)
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
    ListNode* reverseList(ListNode* head) {
        ListNode *new_head = head;
        ListNode *origin_head = head;
        if (nullptr == head) {
            //empty list, do nothing
        } else {
            ListNode *tmp_node = nullptr;
            while (nullptr != origin_head->next) {
                tmp_node = origin_head->next;
                origin_head->next = tmp_node->next;
                tmp_node->next = new_head;
                new_head = tmp_node;
            }
        }
        return new_head;
    }
};
