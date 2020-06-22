//Problem: https://leetcode.com/explore/learn/card/data-structure-tree/17/solve-problems-recursively/535/

//solution1: top-down recursive
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
    int maxDepth(TreeNode* root) {
	int max_depth = 0;
        return tree_depth(root, max_depth);
    }
private:
    int tree_depth(TreeNode *root, int curr_depth)
    {
        int left_depth = 0;
        int right_depth = 0;
        if (nullptr == root) {
            return curr_depth;
        } else {
            left_depth = tree_depth(root->left, curr_depth + 1);
            right_depth = tree_depth(root->right, curr_depth + 1);
        }
        return max(left_depth, right_depth);
    }
};

//solution2: bottom-up recursive
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return max_depth_of_tree(root);
    }
private:
    int max_depth_of_tree(TreeNode *root)
    {
        int left_subtree_depth = 0;
        int right_subtree_depth = 0;
        if (nullptr == root) {
            return 0;
        }
        left_subtree_depth = max_depth_of_tree(root->left);
        right_subtree_depth = max_depth_of_tree(root->right);
        return max(left_subtree_depth, right_subtree_depth) + 1;
    }
};

//solution3: iterative
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode *> node_queue;
        TreeNode *curr_node = nullptr;
        int curr_level_node_count = 0;
        int max_depth = 0;
        
        if (nullptr != root) {
            node_queue.push(root);
            while (!node_queue.empty()) {
                curr_level_node_count = node_queue.size();
                ++max_depth;
                
                for (int i = 0; i < curr_level_node_count; ++i) {
                    curr_node = node_queue.front();
                    if (nullptr != curr_node->left) {
                        node_queue.push(curr_node->left);
                    }
                    if (nullptr != curr_node->right) {
                        node_queue.push(curr_node->right);
                    }
                    node_queue.pop();
                }
            }
        }
        return max_depth;
    }
};

