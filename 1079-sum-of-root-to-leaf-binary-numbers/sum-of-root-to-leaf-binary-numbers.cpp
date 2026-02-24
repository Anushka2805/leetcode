/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
 // digits will shift towards left
// left shift = *2
class Solution {
public:
    int f(TreeNode* root, int val) {
        if (!root) {
            return 0;
        }
        val = (2 * val) + root->val;
        if (root->left == NULL && root->right == NULL) {
            return val;
        }
        return f(root->left, val) + f(root->right, val);
    }
    int sumRootToLeaf(TreeNode* root) { return f(root, 0); }
};