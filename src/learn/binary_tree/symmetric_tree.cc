//Problem: https://leetcode.com/explore/learn/card/data-structure-tree/17/solve-problems-recursively/536/

//solution1:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        bool is_symmetric = true;
        if (nullptr == root) {
            //trival symmetric
        } else {
            is_symmetric = check_symmetric(root->left, root->right);
        }
        return is_symmetric;
    }
    
private:
    bool check_symmetric(TreeNode *left_node, TreeNode *right_node) {
        bool symmetric = true;
        symmetric = check_equal(left_node, right_node);
        if (symmetric && nullptr != left_node && nullptr != right_node) {
            symmetric = check_symmetric(left_node->left, right_node->right);
        }
        if (symmetric && nullptr != left_node && nullptr != right_node) {
            symmetric = check_symmetric(left_node->right, right_node->left);
        }
        return symmetric;
    }
    bool check_equal(TreeNode *left, TreeNode *right) {
        bool equal = false;
        if (nullptr == left && nullptr == right) {
            equal = true;
        } else if (nullptr != left && nullptr != right
                   && left->val == right->val) {
            equal = true;
        }
        return equal;
    }
};

//solution2: time complexity: O(n)  space complexity: O(n)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        bool is_symmetric = true;
        queue<TreeNode *> left_queue;
        queue<TreeNode *> right_queue;
        TreeNode *left_node = nullptr;
        TreeNode *right_node = nullptr;
        if (nullptr == root || is_leaf_node(root)) {
            //trival satisfy
        } else {
            left_queue.push(root->left);
            right_queue.push(root->right);
            //left_queue and right_queue always has same size
            //last while cycle, the element in left_queue and right_queue are all nullptr
            while (!left_queue.empty() && !right_queue.empty()) {
                left_node = left_queue.front();
                left_queue.pop();
                right_node = right_queue.front();
                right_queue.pop();
                if (!is_equal(left_node, right_node)) {
                    is_symmetric = false;
                    break;
                } else if (!left_node && !right_node) {
                    //null node, do nothing
                } else {
                    //critical code, the push order is different
                    left_queue.push(left_node->left);
                    left_queue.push(left_node->right);
                    right_queue.push(right_node->right);
                    right_queue.push(right_node->left);
                }
            }
        }
        return is_symmetric;
    }
    
private:
    bool is_leaf_node(TreeNode *node) {
        return !node->left && !node->right;
    }
    
    bool is_equal(TreeNode *left_node, TreeNode *right_node) {
        bool equal = false;
        if ((!left_node && !right_node)
            || (left_node && right_node && left_node->val == right_node->val)) {
            equal = true;
        }
        return equal;
    }
};
