//Problem: https://leetcode.com/problems/house-robber-iii/
//solution: https://mp.weixin.qq.com/s/z44hk0MW14_mAQd7988mfw

//solution: dp
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
    int rob(TreeNode* root) {
        unordered_map<TreeNode *, int> dp_map;
        return dp_rob(root, dp_map);
    }

private:
    int dp_rob(TreeNode *root, unordered_map<TreeNode *, int> &dp_map)
    {
        int res = 0;
        if (nullptr == root) {
            //do nothing
        } else if (dp_map.end() != dp_map.find(root)) {
            res = dp_map[root];
        } else {
            int do_it = root->val
                + (root->left ? (dp_rob(root->left->left, dp_map) + dp_rob(root->left->right, dp_map)): 0)
                + (root->right ? (dp_rob(root->right->left, dp_map) + dp_rob(root->right->right, dp_map)) : 0);
            int not_do = dp_rob(root->left, dp_map) + dp_rob(root->right, dp_map);
            res = max(do_it, not_do);
            dp_map[root] = res;
        }
        return res;
    }
};

//solution2: dp
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> res(2, 0);
        res = dp_rob(root);
        return max(res[0], res[1]);
    }

private:
    vector<int> dp_rob(TreeNode *root)
    {
        vector<int> res(2, 0);
        vector<int> left(2, 0);
        vector<int> right(2, 0);
        if (nullptr == root) {
            //do nothing
        } else {
            left = dp_rob(root->left);
            right = dp_rob(root->right);
            //here is critical
            res[0] = max(left[0], left[1]) + max(right[0], right[1]);
            res[1] = left[0] + right[0] + root->val;
        }
        return res;
    }
};
