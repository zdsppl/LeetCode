//Problem: https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/929/

//solution1: recursive   time complexity: O(n)   space complexity: O(1)
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> node_vals;
        traversal(root, node_vals);
        return node_vals;
    }
    
private:
    void traversal(TreeNode *root, vector<int> &node_vals) {
        if (nullptr != root) {
            traversal(root->left, node_vals);
            node_vals.push_back(root->val);
            traversal(root->right, node_vals);
        }
    }
};

//solution2: iterative   time complexity: O(n)  
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> node_vals;
        stack<TreeNode *> parent_node_stack;
        TreeNode *curr_node = nullptr;
        TreeNode *tmp_node = nullptr;
        
        if (nullptr != root) {
            parent_node_stack.push(root);
            curr_node = root->left;
            while (!parent_node_stack.empty()) {
                while (nullptr != curr_node) {
                    parent_node_stack.push(curr_node);
                    curr_node = curr_node->left;
                }
                
                tmp_node = parent_node_stack.top();
                node_vals.push_back(tmp_node->val);
                curr_node = tmp_node->right;
                parent_node_stack.pop();
		//pop first, then push the right child
                if (nullptr != curr_node) {
                    parent_node_stack.push(curr_node);
                    curr_node = curr_node->left;
                }
            }
        }
        return node_vals;
    }
};
