//Problem: https://leetcode.com/explore/learn/card/data-structure-tree/133/conclusion/942/

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build_tree_internal(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    
private:
    TreeNode *build_tree_internal(vector<int> &inorder, int inorder_left, int inorder_right,
                                  vector<int> &postorder, int postorder_left, int postorder_right)
    {
        TreeNode *curr = nullptr;
        int root_index = 0;
        int next_inorder_left = 0;
        int next_inorder_right = 0;
        int next_postorder_left = 0;
        int next_postorder_right = 0;
        if (inorder_left > inorder_right || postorder_left > postorder_right) {
            //do nothing
        } else {
            curr = new TreeNode(postorder[postorder_right]);
            //find the root node,and split the tree to two subtree
            for (root_index = inorder_left; root_index <= inorder_right; ++root_index) {
                if (curr->val == inorder[root_index]) {
                    break;
                }
            }
            next_inorder_left = inorder_left;
            next_inorder_right = root_index - 1;
            next_postorder_left = postorder_left;
            //(root_index - inorder_left) is the node count of current left subtree
            //so the next_postorder_right is postorder_left + (root_index - inorder_left) - 1
            next_postorder_right = postorder_left + (root_index - inorder_left) - 1;
            curr->left = build_tree_internal(inorder, next_inorder_left, next_inorder_right,
                                             postorder, next_postorder_left, next_postorder_right);
            next_inorder_left = root_index + 1;
            next_inorder_right = inorder_right;
            next_postorder_left = postorder_left + (root_index - inorder_left);
            //the postorder_right is curr root node ,so decrease 1;
            next_postorder_right = postorder_right - 1;
            curr->right = build_tree_internal(inorder, next_inorder_left, next_inorder_right,
                                              postorder, next_postorder_left, next_postorder_right);
        }
        
        return curr;
    }
};
