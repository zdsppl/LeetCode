//Problem: https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/928/

//solution1: recursive. time complexity: O(n)   space complexity: O(1)
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> node_vals;
        traversal(root, node_vals);
        return node_vals;
    }
private:
    void traversal(TreeNode *root, vector<int> &node_vals) {
        if (nullptr != root) {
            node_vals.push_back(root->val);
            traversal(root->left, node_vals);
            traversal(root->right, node_vals);
        }
    }
};

//solution2: iterative.  time complexity: O(n)   space complexity: O(n)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode *curr_node = nullptr;
        vector<int> node_vals;
        std::stack<TreeNode *> parent_node_stack;
        
        if (nullptr != root) {
            parent_node_stack.push(root);        
            while (!parent_node_stack.empty()) {
                curr_node = parent_node_stack.top();
                parent_node_stack.pop();
                node_vals.push_back(curr_node->val);
                if (nullptr != curr_node->right) {
                    parent_node_stack.push(curr_node->right);
                }
                if (nullptr != curr_node->left) {
                    parent_node_stack.push(curr_node->left);
                }
            }
        }
        return node_vals;
    }

};
