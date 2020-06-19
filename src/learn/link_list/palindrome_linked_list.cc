//Problem: https://leetcode.com/explore/learn/card/linked-list/219/classic-problems/1209/
//analyze article: https://blog.csdn.net/qq_40938077/article/details/80213789

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
    bool isPalindrome(ListNode* head) {
        bool ret = false;
        if (nullptr == head || nullptr == head->next) {
	    //for case:[] or [1]
            ret = true;
        } else {
            ListNode *middle_node = find_middle_node(head);
            ListNode *right_half_head = reverse_list(middle_node->next);
            ListNode *left_half_head = head;
            ret = true;
            while (nullptr != right_half_head) {
                if (left_half_head->val != right_half_head->val) {
		    //there can rever the right half list if need
                    ret = false;
                    break;
                }
                left_half_head = left_half_head->next;
                right_half_head = right_half_head->next;
            }
        }
        return ret;
    }
private:
    ListNode *find_middle_node(ListNode *head)
    {
        ListNode *fast_ptr = head;
        ListNode *slow_ptr = head;
        if (nullptr != head && nullptr != head->next) {
            while (nullptr != fast_ptr && nullptr != fast_ptr->next) {
                fast_ptr = fast_ptr->next->next;
                if (nullptr != fast_ptr) {
                    slow_ptr = slow_ptr->next;
                }
            }
        }
        return slow_ptr;
    }
    
    ListNode *reverse_list(ListNode *head)
    {
        ListNode *origin_head = head;
        ListNode *new_head = head;
        ListNode *tmp_node = nullptr;
        if (nullptr != head && nullptr != head->next) {
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
