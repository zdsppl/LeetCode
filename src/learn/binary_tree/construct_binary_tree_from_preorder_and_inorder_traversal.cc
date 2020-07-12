//Problem: https://leetcode.com/explore/learn/card/data-structure-tree/133/conclusion/943/

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build_tree_internal(preorder, 0, preorder.size() - 1,
                                   inorder, 0, inorder.size() - 1);
    }
    
private:
    TreeNode *build_tree_internal(vector<int> &preorder, int preorder_left, int preorder_right,
                                  vector<int> &inorder, int inorder_left, int inorder_right)
    {
        TreeNode *curr = nullptr;
        int root_index = 0;
        int next_preorder_left = 0;
        int next_preorder_right = 0;
        int next_inorder_left = 0;
        int next_inorder_right = 0;
        if (preorder_left > preorder_right || inorder_left > inorder_right) {
            //do nothing
        } else {
            curr = new TreeNode(preorder[preorder_left]);
            for (root_index = inorder_left; root_index <= inorder_right; ++root_index) {
                if (curr->val == inorder[root_index]) {
                    break;
                }
            }
            next_inorder_left = inorder_left;
            next_inorder_right = root_index - 1;
            next_preorder_left = preorder_left + 1;
            next_preorder_right = preorder_left + (root_index - inorder_left);
            curr->left = build_tree_internal(preorder, next_preorder_left, next_preorder_right,
                                             inorder, next_inorder_left, next_inorder_right);
            next_inorder_left = root_index + 1;
            next_inorder_right = inorder_right;
            next_preorder_left = preorder_left + (root_index - inorder_left) + 1;
            next_preorder_right = preorder_right;
            curr->right = build_tree_internal(preorder, next_preorder_left, next_preorder_right,
                                              inorder, next_inorder_left, next_inorder_right);
        }
        return curr;
    }
};
