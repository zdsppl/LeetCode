//Problem: https://leetcode.com/explore/learn/card/linked-list/213/conclusion/1227/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *new_head = nullptr;
        ListNode *new_tail = nullptr;
        ListNode *l1_cursor = l1;
        ListNode *l2_cursor = l2;
        ListNode *target_node = nullptr;
        if (nullptr == l1_cursor && nullptr == l2_cursor) {
            //do nothing, two empty list
        } else if (nullptr != l1_cursor && nullptr == l2_cursor) {
            new_head = l1_cursor;
        } else if (nullptr == l1_cursor && nullptr != l2_cursor) {
            new_head = l2_cursor;
        } else {
            while (nullptr != l1_cursor && nullptr != l2_cursor) {
                if (l1_cursor->val <= l2_cursor->val) {
                    target_node = l1_cursor;
                    l1_cursor = l1_cursor->next;
                } else {
                    target_node = l2_cursor;
                    l2_cursor = l2_cursor->next;
                }
                
                if (nullptr == new_head) {
                    new_head = target_node;
                    new_tail = target_node;
                } else {
                    new_tail->next = target_node;
                    new_tail = target_node;
                }
            }
            
            if (nullptr != l1_cursor) {
                new_tail->next = l1_cursor;
            }
            if (nullptr != l2_cursor) {
                new_tail->next = l2_cursor;
            }       
        }
        
        return new_head;
    }
    
};

