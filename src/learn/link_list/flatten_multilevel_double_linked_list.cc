//Problem: https://leetcode.com/explore/learn/card/linked-list/213/conclusion/1225/
//Refence: https://www.cnblogs.com/grandyang/p/9688522.html

//solution: recursive function
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *curr = head;
        Node *parent_next = nullptr;
        Node *child_last = nullptr;
        while (nullptr != curr) {
            if (nullptr != curr->child) {
                parent_next = curr->next;
                flatten(curr->child);
                child_last = curr->child;
                while (nullptr != child_last->next) {
                    child_last = child_last->next;
                }
                curr->next = curr->child;
                curr->child->prev = curr;
                child_last->next = parent_next;
                if (nullptr != parent_next) {
                    parent_next->prev = child_last;
                }
                curr->child = nullptr;
            }
            curr = curr->next;
        }
        return head;
    }
};

//solution2: while loop
ass Solution {
public:
    Node* flatten(Node* head) {
        Node *curr = head;
        Node *parent_next = nullptr;
        Node *child_last = nullptr;
        while (nullptr != curr) {
            if (nullptr != curr->child) {
                parent_next = curr->next;
                child_last = curr->child;
                while (nullptr != child_last->next) {
                    child_last = child_last->next;
                }
                curr->next = curr->child;
                curr->child->prev = curr;
                child_last->next = parent_next;
                if (nullptr != parent_next) {
                    parent_next->prev = child_last;
                }
                curr->child = nullptr;
            }
            curr = curr->next;
        }
        return head;
    }
};
