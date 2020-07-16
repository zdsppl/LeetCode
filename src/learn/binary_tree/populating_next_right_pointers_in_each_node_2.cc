//Problem: https://leetcode.com/explore/learn/card/data-structure-tree/133/conclusion/1016/

//solution1: iterative
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
                prev_node = pop_and_add_child(node_queue);
                for (int i = 1; i < size; ++i) {
                    curr_node = pop_and_add_child(node_queue);
                    prev_node->next = curr_node;
                    prev_node = curr_node;
                }
            }
        }
        
        return root;
    }
private:
    Node *pop_and_add_child(queue<Node *> &node_queue)
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

//solution2: recursive
class Solution {
public:
    
    Node* connect(Node* root) {
        internal_connect(root);
        return root;
    }

private:
    void internal_connect(Node *root)
    {
        if (!root) {
            //empty tree, do nothing
        } else {
            Node *tmp_node = nullptr;
            Node *neighbor = root->next;
            while (neighbor) {
                if (neighbor->left) {
                    tmp_node = neighbor->left;
                    break;
                }
                if (neighbor->right) {
                    tmp_node = neighbor->right;
                    break;
                }
                neighbor = neighbor->next;
            }
            if (root->right) {
                root->right->next = tmp_node;
            }
            if (root->left) {
                root->left->next = root->right ? root->right : tmp_node;
            }
            //这里很重要，必须先递归右子树,比如下面的例子9是叶子节点，如果先遍历左子树，那么2->1->0就无法继续指向8->8
	    /*                 2
                              / \
                             1   3
                            / \ / \
                           0  7 9  1
                          /  / \  / \
                         2  1   0 8  8
                               /
                              7
            */
            internal_connect(root->right);
            internal_connect(root->left);
        }
    }
};
