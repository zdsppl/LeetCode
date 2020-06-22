//Problem: https://leetcode.com/explore/learn/card/data-structure-tree/134/traverse-a-tree/931/

//solution1: iterasive
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        const int QUEUE_ARR_SIZE = 2;
        queue<TreeNode *> queue_arr[QUEUE_ARR_SIZE];
        int curr_index = 0;
        vector<int> level_vector;
        vector<vector<int>> res_vector;
        TreeNode *tmp_node = nullptr;
        if (nullptr != root) {
            queue_arr[curr_index % QUEUE_ARR_SIZE].push(root);
            while (!queue_arr[0].empty() || !queue_arr[1].empty()) {
                tmp_node = queue_arr[curr_index % QUEUE_ARR_SIZE].front();
                level_vector.push_back(tmp_node->val);          
                
                if (nullptr != tmp_node->left) {
                    queue_arr[(curr_index + 1) % QUEUE_ARR_SIZE].push(tmp_node->left);
                }
                if (nullptr != tmp_node->right) {
                    queue_arr[(curr_index + 1) % QUEUE_ARR_SIZE].push(tmp_node->right);
                }
                
                queue_arr[curr_index % QUEUE_ARR_SIZE].pop();
                if (queue_arr[curr_index % QUEUE_ARR_SIZE].empty()) {
                    res_vector.push_back(level_vector);
                    level_vector.clear();
                    ++curr_index;
                }
            }
        }
        return res_vector;
    }
};

//solution2: iterasive
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> node_queue;
        TreeNode *curr_node = nullptr;
        vector<vector<int>> res_vector;
        vector<int> curr_level_vector;
        int curr_level_node_count = 0;
        
        if (nullptr != root) {
            node_queue.push(root);
            while (!node_queue.empty()) {
                curr_level_node_count = node_queue.size();
                curr_level_vector.clear();
                for (int i = 0; i < curr_level_node_count; ++i) {
                    curr_node = node_queue.front();
                    if (nullptr != curr_node->left) {
                        node_queue.push(curr_node->left);
                    }
                    if (nullptr != curr_node->right) {
                        node_queue.push(curr_node->right);
                    }
                    curr_level_vector.push_back(curr_node->val);
                    node_queue.pop();
                }
                res_vector.push_back(curr_level_vector);
            }
        }
        return res_vector;
    }
};

//solution3: tail recursive
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode *> start_nodes;
        vector<vector<int>> res_vector;
        if (nullptr != root) {
            start_nodes.push_back(root);
            level_order_internal(start_nodes, res_vector);
        }
        return res_vector;
    }
private:
    void level_order_internal(const vector<TreeNode *> &nodes, vector<vector<int>> &res_vector) {
        if (!nodes.empty()) {
            vector<TreeNode *> next_level_nodes;
            TreeNode *tmp_node = nullptr;
            vector<int> curr_level_node_vals;
            for (int i = 0; i < nodes.size(); ++i) {
                tmp_node = nodes[i];
                curr_level_node_vals.push_back(tmp_node->val);
                if (nullptr != tmp_node->left) {
                    next_level_nodes.push_back(tmp_node->left);
                }
                if (nullptr != tmp_node->right) {
                    next_level_nodes.push_back(tmp_node->right);
                }
            }
            res_vector.push_back(curr_level_node_vals);
            level_order_internal(next_level_nodes, res_vector);          
        }
    }
};
