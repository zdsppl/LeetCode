//Problem: https://leetcode.com/problems/partition-list/

//solution1:
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *new_head = head;
        ListNode *partition_point = head; //last node less than x
        ListNode *prev_node = nullptr;
        ListNode *cursor_node = nullptr;
        
        if (!head) {
            //empty list, do nothing
        } else {
            while (partition_point && partition_point->val < x) {
                prev_node = partition_point;
                partition_point = partition_point->next;
            }        
            if (!partition_point) {
                //all node less than x, do nothing
            } else {
                if (head == partition_point) {
                    //the head equal or more than x,so the head will change
                    cursor_node = partition_point->next;
                    prev_node = partition_point;
                    while (cursor_node) {
                        if (cursor_node->val < x) {
                            prev_node->next = cursor_node->next;
                            cursor_node->next = head;
                            new_head = cursor_node;
                            partition_point = new_head;
                            cursor_node = prev_node->next;
                            break;
                        } else {
                            prev_node = cursor_node;
                            cursor_node = cursor_node->next;
                        }
                    }
                } else {
                    cursor_node = partition_point->next;
                    partition_point = prev_node;
                    prev_node = partition_point->next;
                }
                
                while (cursor_node) {
                    if (cursor_node->val < x) {
                        prev_node->next = cursor_node->next;
                        cursor_node->next = partition_point->next;
                        partition_point->next = cursor_node;
                        partition_point = cursor_node;
                        cursor_node = prev_node->next;
                    } else {
                        prev_node = cursor_node;
                        cursor_node = cursor_node->next;
                    }
                }
            }
        }
        
        return new_head;
    }
};

//solution2:
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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy_left_head; //head of list which val less than x
        ListNode *dummy_left_tail = &dummy_left_head;
        ListNode dummy_right_head; //head of list which val equal or greater than x
        ListNode *dummy_right_tail = &dummy_right_head;
        ListNode *new_head =  nullptr;
        ListNode *cursor_node = head;
        
        while (cursor_node) {
            if (cursor_node->val < x) {
                dummy_left_tail->next = cursor_node;
                dummy_left_tail = cursor_node;
            } else {
                dummy_right_tail->next = cursor_node;
                dummy_right_tail = cursor_node;
            }
            cursor_node = cursor_node->next;
        }
        dummy_right_tail->next = nullptr;
        dummy_left_tail->next = dummy_right_head.next;
        new_head = dummy_left_head.next;
        return new_head;
    }
};
