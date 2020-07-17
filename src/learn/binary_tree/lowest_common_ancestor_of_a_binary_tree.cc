//Problem: https://leetcode.com/explore/learn/card/data-structure-tree/133/conclusion/932/

//solution1: from low to high, transave every subtree, find the two node
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ancestor = nullptr;
        lowest_common_ancestor_internal(root, p, q, ancestor);
        return ancestor;
    }
    
private:
    void lowest_common_ancestor_internal(TreeNode *root, const TreeNode *first,
                                         const TreeNode *second, TreeNode *&ancestor)
    {
        bool find_both = false;
	//if ancestor not nullptr, has find the ancestor.so return directly
        if (!root || ancestor) {
            //empty tree, do nothing
        } else {
            lowest_common_ancestor_internal(root->left, first, second, ancestor);
            lowest_common_ancestor_internal(root->right, first, second, ancestor);
	    //here, if ancestor not nullptr, has find the ancestor
            if (!ancestor && contain_both(root, first, second)) {
                ancestor = root;
            }
        }
    }
    bool contain_both(TreeNode *root, const TreeNode *first,
                      const TreeNode *second)
    {
        bool find_first = false;
        bool find_second = false;
        if (!root) {
            //empty tree, do nothing
        } else {
            contain_both_internal(root, first, second, find_first, find_second);
        }
        return find_first && find_second;
    }
    void contain_both_internal(TreeNode *root, const TreeNode *first,
                               const TreeNode *second,
                               bool &find_first, bool &find_second)
    {
        if (!root) {
            //empty tree, do nothing
        } else {
            if (first->val == root->val) {
                find_first = true;
            }
            if (second->val == root->val) {
                find_second = true;
            }
            contain_both_internal(root->left, first, second, find_first, find_second);
            contain_both_internal(root->right, first, second, find_first, find_second);
        }
    }
};

//solution2: find the path to target nodes, then find the max common prefix
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        TreeNode *ancestor = nullptr;
        vector<TreeNode *> path_p;
        vector<TreeNode *> path_q;
        int level = 0;
        
        if (!root) {
            
        } else {
            find_path(root, p, path_p);
            find_path(root, q, path_q);
            while (level < path_p.size() && level < path_q.size()
                && path_p[level] == path_q[level]) {
                ++level;
            }
            ancestor = path_p[level - 1];
        }
        return ancestor;
    }
    
private:
    bool find_path(TreeNode *root, const TreeNode *target_node, vector<TreeNode *> &path)
    {
        bool found = false;
        if (!root) {
            //empty tree, do nothing
        } else {
            path.push_back(root);
            if (target_node == root) {
                found = true;
            } else {
                found = find_path(root->left, target_node, path);
                if (!found) {
                    found = find_path(root->right, target_node, path);
                }
            }
            if (!found) {
                path.pop_back();
            }
        }
        return found;
    }
};
