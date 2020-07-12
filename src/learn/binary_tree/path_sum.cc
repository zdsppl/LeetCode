//Problem: https://leetcode.com/explore/learn/card/data-structure-tree/17/solve-problems-recursively/537/

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
    bool hasPathSum(TreeNode* root, int sum) {
        bool res = false;
        if (root) {
            res = check_path_sum(root, 0, sum);
        }
        return res;
    }
private:
    /*
    bool check_path_sum(TreeNode *node, int curr_sum, const int target_sum) {
        bool res = false;
        curr_sum += node->val;
        if (is_leaf_node(node) && (target_sum == curr_sum)) {
            res = true;
        } else {
            if (node->left) {
                res = check_path_sum(node->left, curr_sum, target_sum);
            }
            if (!res && node->right) {
                res = check_path_sum(node->right, curr_sum, target_sum);
            }
        }
        return res;
    }
    */
    
    bool check_path_sum2(TreeNode *node, int curr_sum, const int target_sum) {
        bool res = false;
        if (!node) {
            return false;
        } else {
            curr_sum += node->val;
            if (is_leaf_node(node) && (target_sum == curr_sum)) {
                return true;
            }
        }
        return check_path_sum2(node->left, curr_sum, target_sum)
            || check_path_sum2(node->right, curr_sum, target_sum);
    }

    bool check_path_sum3(TreeNode *node, int sum) {
        bool res = false;
        if (!node) {
            res = false;
        } else {
            sum -= node->val;
            if (is_leaf_node(node) && (0 == sum)) {
                res = true;
            } else {
                res = check_path_sum3(node->left, sum) || check_path_sum3(node->right, sum);
            }
        }
        return res;
    }
    
    bool is_leaf_node(TreeNode *node) {
        return !node->left && !node->right;
    }
};

//solution2: like a pre-order transaval
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        bool res = false;
        unordered_map<TreeNode *, int> curr_sum_map;
        stack<TreeNode *> node_stack;
        TreeNode *tmp_node = nullptr;
        int curr_sum = 0;
        if (root) {
            node_stack.push(root);
            curr_sum_map[root] = root->val;
            while (!node_stack.empty()) {
                tmp_node = node_stack.top();
                node_stack.pop();
                curr_sum = curr_sum_map[tmp_node];
                if (is_leaf_node(tmp_node) && (sum == curr_sum)) {
                    res = true;
                    break;
                } else {
                    if (nullptr != tmp_node->right) {
                        node_stack.push(tmp_node->right);
                        curr_sum_map[tmp_node->right] = curr_sum + tmp_node->right->val;
                    }
                    
                    if (nullptr != tmp_node->left) {
                        node_stack.push(tmp_node->left);
                        curr_sum_map[tmp_node->left] = curr_sum + tmp_node->left->val;
                    }
                }
            }
        }
        return res;
    }
private:

    bool is_leaf_node(TreeNode *node) {
        return !node->left && !node->right;
    }
}; 
