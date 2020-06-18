//Problem: https://leetcode.com/explore/learn/card/linked-list/219/classic-problems/1208/

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
    ListNode* oddEvenList(ListNode* head) {
        if (head && head->next && head->next->next) { 
            ListNode *odd_head = head;
            ListNode *even_head = head->next;
            ListNode *tmp_odd = odd_head;
            ListNode *tmp_even = even_head;
            while (tmp_odd->next && tmp_even->next) {
                tmp_odd->next = tmp_odd->next->next;
                tmp_even->next = tmp_even->next->next;
                tmp_odd = tmp_odd->next;
                tmp_even = tmp_even->next;
            }
            tmp_odd->next = even_head;
        }
        return head;
    }
};
