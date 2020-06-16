//Problem: https://leetcode.com/explore/learn/card/linked-list/214/two-pointer-technique/1214/
//Analyze link: https://blog.csdn.net/willduan1/article/details/50938210

//solution1
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
    ListNode *detectCycle(ListNode *head) {
        bool has_cycle = false;
        ListNode *first_cycle_node = nullptr;
        if (nullptr != head) {
            int index = 0;
            ListNode *slow_ptr = head;
            ListNode *fast_ptr = head;
            if (nullptr != fast_ptr->next) {
                fast_ptr = fast_ptr->next->next;
            } else {
                fast_ptr = fast_ptr->next;
            }
            while (nullptr != fast_ptr && nullptr != fast_ptr->next) {
                if (slow_ptr == fast_ptr) {
                    has_cycle = true;
                    break;
                } else {
                    fast_ptr = fast_ptr->next->next;
                    slow_ptr = slow_ptr->next;
                    ++index;
                }
            }
            if (has_cycle) {
                ListNode *tmp_node = head->next;
                first_cycle_node = head;
                bool found = false;
                for (int i = 0; i <= index; ++i) {
                    for (int j = i; j <= 2 * index + 2; ++j) {
                        if (first_cycle_node == tmp_node) {
                            found = true;
                            break;
                        } else {
                            tmp_node = tmp_node->next;
                        }
                    }
                    if (found) {
                        break;
                    } else {
                        first_cycle_node = first_cycle_node->next;
                    }
                }
            }            
        }
        return first_cycle_node;
    }
};

//solution2
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
    ListNode *detectCycle(ListNode *head) {
      ListNode* slow = head;
      ListNode* fast = head;
      while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
          while (slow != head) {
            slow = slow->next;
            head = head->next;
          }
          return slow;
        }
      }
      return nullptr;
    }
};

//solution3
/* node1-->node2-->node3-->node4-->node5-->node6-->node7-->node8
			    ^				     |
			    |                                |
			    |--------------------------------|
in this case, slow_ptr and fast_ptr meet at node6
s: the length of slow_ptr move when fast_ptr meet slow_ptr
l: the length of the linked list
r: the length of the cycle
a: the length from first node of linked list to first node of cycle
x: the length from first node of cycle to meet node
Dfast: the length of fast_ptr move when fast_ptr meet slow_ptr
Dfast = 2 * s becasue fast's move speed is double of slow's speed
2 * s = s + n * r (n >= 1)
      ||
      \/
s = n * r
      ||
      \/
a + x + m * r = n * r (m < n)
      ||
      \/
a + x = n' * r (n' = n - m, n' >= 1)
      ||
      \/
a + x = (n - 1) * r + r
      ||
      \/
a + x = (n - 1) * r + (l -a) (r = l -a)
      ||
      \/
a = (n - 1) * r + (l - a -x)
l - a - x is the length from meet node to first node of cycle, so the head ptr and fast_ptr move one node per time, they will meet fast_ptr at the first node of the cycle

in the above case: s = 4, l = 8 , r = 5, a = 3, x = 1
2 * 5 + = 5 + 1 * 5
        ||
        \/
5 = 1 * 5
        ||
        \/
3 + 2 = 0 * 5 + 5
        ||
        \/
3 + 2 = 0 * 5 + (8 - 3)
        ||
        \/
3 = 0 * 5 + (8 - 3 - 2)
      
class Solution {
private:
    ListNode *isCycle(ListNode *head){
        ListNode * slow =head;
        ListNode * fast =head;
        do{
            slow = slow->next;
            fast = fast->next;
            if(fast)fast =fast->next;
        }while(fast && fast!=slow );
        return fast;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head){
            return NULL;
        }
        ListNode *p2 = isCycle(head);
        if(p2==NULL)
            return NULL;
        else{
            ListNode *p1 =head;
            while(p2!=p1){
                p2=p2->next;
                p1=p1->next;
            }
            return p2;
        }
            
    }
};
