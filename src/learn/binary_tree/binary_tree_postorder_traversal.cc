//Problem: https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/930/

//solution1: recursive.  time complexity: O(n)   space complexity: O(1)
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> node_vals;
        traversal(root, node_vals);
        return node_vals;
    }
private:
    void traversal(TreeNode *root, vector<int> &node_vals)
    {
        if (nullptr != root) {
            traversal(root->left, node_vals);
            traversal(root->right, node_vals);
            node_vals.push_back(root->val);
        }
    }
};

//solution2: iterative. destroy the tree struct 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> node_vals;
        stack<TreeNode *> node_stack;
        TreeNode *curr_node = nullptr;
        TreeNode *tmp_node = nullptr;
        
        if (nullptr != root) {
            node_stack.push(root);
            while (!node_stack.empty()) {
                curr_node = node_stack.top();
                
                if (nullptr == curr_node->left && nullptr == curr_node->right) {
                    node_vals.push_back(curr_node->val);
                    node_stack.pop();
                } else {
                    if (nullptr != curr_node->right) {
                        node_stack.push(curr_node->right);
                        curr_node->right = nullptr;
                    }
                    if (nullptr != curr_node->left) {
                        node_stack.push(curr_node->left);
                        curr_node->left = nullptr;
                    }
                }
            }
        }
        return node_vals;
    }
};

//solution3: iterative. not destroy the tree struct
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> node_vals;
        stack<TreeNode *> node_stack;
        TreeNode *curr_node = nullptr;
        TreeNode *tmp_node = nullptr;
        unordered_map<TreeNode *, bool> node_traversal_map;
        
        if (nullptr != root) {
            node_stack.push(root);
            node_traversal_map[root] = false;
            while (!node_stack.empty()) {
                curr_node = node_stack.top();
                
                if (node_traversal_map[curr_node]) {
                    node_vals.push_back(curr_node->val);
                    node_stack.pop();
                } else {
                    if (nullptr != curr_node->right) {
                        node_stack.push(curr_node->right);
                        node_traversal_map[curr_node->right] = false;
                    }
                    if (nullptr != curr_node->left) {
                        node_stack.push(curr_node->left);
                        node_traversal_map[curr_node->left] = false;
                    }
                    node_traversal_map[curr_node] = true;
                }
            }
        }
        return node_vals;
    }
};
