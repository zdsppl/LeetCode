//Problem: https://leetcode.com/explore/learn/card/linked-list/213/conclusion/1228/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = nullptr;
        if (nullptr == l1 && nullptr == l2) {
            //do nothing, two empty list
        } else if (nullptr != l1 && nullptr == l2) {
            result = l1;
        } else if (nullptr == l1 && nullptr != l2) {
            result = l2;
        } else {
            result = l1;
            ListNode *tail = l1;
            ListNode *l1_cursor = l1;
            ListNode *l2_cursor = l2;
            int added_value = 0;
            bool carry = false;//进位
            int dummy_value = 0;
            
            while (nullptr != l1_cursor && nullptr != l2_cursor) {
                l1_cursor->val = add_operation(l1_cursor->val, l2_cursor->val, carry);
                tail = l1_cursor;
                l1_cursor = l1_cursor->next;
                l2_cursor = l2_cursor->next;       
            }
            
            while (nullptr != l1_cursor) {
                l1_cursor->val = add_operation(l1_cursor->val, dummy_value, carry);
                tail = l1_cursor;
                l1_cursor = l1_cursor->next;
            }
            
            while (nullptr != l2_cursor) {
                l2_cursor->val = add_operation(l2_cursor->val, dummy_value, carry);
                tail->next = l2_cursor;
                tail = l2_cursor;
                l2_cursor = l2_cursor->next;
            }
            
            //for case like [5], [5]
            if (carry) {
                ListNode *node = new ListNode(1);
                tail->next = node;
                tail = node;
            }
        }
        return result;
    }
private:
    int add_operation(int left, int right, bool &carry)
    {
        int result = left + right;
        if (carry) {
            result += 1;
            carry = false;
        }
        if (result >= 10) {
            result %= 10;
            carry = true;
        }
        return result;
    }
};
