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
    int func(TreeNode* root, int curr) {
        if (root == nullptr) return 0;

        curr = (curr << 1) | root->val;

        if (root->left == nullptr && root->right == nullptr)
            return curr;

        return func(root->left, curr) + func(root->right, curr);
    }

    int sumRootToLeaf(TreeNode* root) {
        return func(root, 0);
    }
};