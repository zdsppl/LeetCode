//Problem: https://leetcode.com/explore/learn/card/linked-list/213/conclusion/1229/

//solution 1: time complexity: O(n)   space complexity: O(n)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *curr = head;
        Node *new_head = nullptr;
        Node *new_tail = nullptr;
        Node *new_node = nullptr;
        std::vector<Node *> nodes;
        int index = 0;
        std::map<Node *, int> node_index_map;
        
        if (nullptr != curr) {
            new_node = new Node(curr->val);
            new_head = new_node;
            new_tail = new_node;
            nodes.push_back(new_node);
            node_index_map[curr] = index;
            curr = curr->next;
            ++index;
        }
        while (nullptr != curr) {
            new_node = new Node(curr->val);
            new_tail->next = new_node;
            new_tail = new_node;
            nodes.push_back(new_node);
            node_index_map[curr] = index;
            curr = curr->next;
            ++index;
        }
        
        Node *old_list_curr = head;
        Node *new_list_curr = new_head;
        int random_index = 0;
        while (nullptr != old_list_curr && nullptr != new_list_curr) {
            if (nullptr != old_list_curr->random) {
                random_index = node_index_map[old_list_curr->random];
                new_list_curr->random = nodes[random_index];
            } else {
                new_list_curr->random = nullptr;
            }
            old_list_curr = old_list_curr->next;
            new_list_curr = new_list_curr->next;
        }
        return new_head;
    }
};

//solution2: time complexity: O(n)  space complexity: O(n)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *origin_list_curr = head;
        Node *new_list_head = nullptr;
        Node *new_list_curr = nullptr;
        Node *new_node = nullptr;
        std::unordered_map<Node *, Node *> origin_new_node_map;
        
        if (nullptr != origin_list_curr) {
            new_node = new Node (origin_list_curr->val);
            new_list_head = new_node;
            new_list_curr = new_node;
            origin_new_node_map[origin_list_curr] = new_node;
            origin_list_curr = origin_list_curr->next;
        }
        
        while (nullptr != origin_list_curr) {
            new_node = new Node (origin_list_curr->val);
            new_list_curr->next = new_node;
            new_list_curr = new_node;
            origin_new_node_map[origin_list_curr] = new_node;
            origin_list_curr = origin_list_curr->next;
        }
        
        origin_list_curr = head;
        new_list_curr = new_list_head;
        while (nullptr != origin_list_curr && nullptr != new_list_curr) {
            new_list_curr->random = origin_new_node_map[origin_list_curr->random];
            origin_list_curr = origin_list_curr->next;
            new_list_curr = new_list_curr->next;
        }
        
        return new_list_head;
    }
};
