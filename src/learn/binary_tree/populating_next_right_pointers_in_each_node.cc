//Problem: https://leetcode.com/explore/learn/card/data-structure-tree/133/conclusion/994/

//solution1: iterative. time complexity: O(n)  space complexity:O(n)
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node *> node_queue;
        Node *prev_node = nullptr;
        Node *curr_node = nullptr;
        int size = 0;
        if (!root) {
            //empty tree, do nothing
        } else {
            node_queue.push(root);
            while (!node_queue.empty()) {
                size = node_queue.size();
                prev_node = pop_and_push_child(node_queue);
                for (int i = 1; i < size; ++i) {
                    curr_node = pop_and_push_child(node_queue);
                    prev_node->next = curr_node;
                    prev_node = curr_node;
                }
            }
        }
        return root;
    }
private:
    Node *pop_and_push_child(queue<Node *> &node_queue)
    {
        Node *curr_node = nullptr;
        if (!node_queue.empty()) {
            curr_node = node_queue.front();
            node_queue.pop();
            if (curr_node->left) {
                node_queue.push(curr_node->left);
            }
            if (curr_node->right) {
                node_queue.push(curr_node->right);
            }
        }
        return curr_node;
    }
};

//solution2: iterative. time complexity: O(n)  space complexity:O(1)
class Solution {
public:
    Node* connect(Node* root) {
        if (root && root->left && root->right) {
            Node *dummy_node = new Node(); //dummy_node->next always point to next level head node
            Node *curr_node = nullptr; //curr_node will been set to dummy_node when iterative new level
            Node *tmp_root = root; //for not modify root
            dummy_node->next = root->left;
            curr_node = dummy_node;
            while (tmp_root) {
                if (tmp_root->left) {
                    curr_node->next = tmp_root->left;
                    curr_node = tmp_root->left;
                }
                
                if (tmp_root->right) {
                    curr_node->next = tmp_root->right;
                    curr_node = tmp_root->right;
                }
                
                tmp_root = tmp_root->next;
                if (!tmp_root) {
                    tmp_root = dummy_node->next;
                    if (dummy_node->next) {
                        dummy_node->next = dummy_node->next->left;
                    }
                    curr_node = dummy_node;
                }
            }
        }
        return root;
    }
};

//solution3: recursive
class Solution {
public:
    Node* connect(Node* root) {
        if (root) {
            internal_connect(root->left, root->right);
        }
        return root;
    }
private:
    void internal_connect(Node *left_node, Node *right_node)
    {
        if (!left_node || !right_node) {
            //do nothing
        } else {
            left_node->next = right_node;
            internal_connect(left_node->left, left_node->right);
            internal_connect(right_node->left, right_node->right);
            internal_connect(left_node->right, right_node->left);
        }
    }
};

//solution4: recursive
class Solution {
public:
    Node* connect(Node* root) {
        if (root) {
            internal_connect(root);
        }
        return root;
    }
private:
    void internal_connect(Node *root)
    {
        Node *neighbor = nullptr;
        if (!root || is_leaf(root)) {
            //empty tree, do nothing
        } else {
            root->left->next = root->right;
            if (neighbor = root->next) {
                root->right->next = neighbor->left;
            }
            internal_connect(root->left);
            internal_connect(root->right);
        }
    }
    bool is_leaf(Node *node) 
    {
        return !node->left && !node->right;
    }
};
