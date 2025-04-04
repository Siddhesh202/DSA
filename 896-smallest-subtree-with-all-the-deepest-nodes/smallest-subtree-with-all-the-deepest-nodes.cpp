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
#define P pair<int, TreeNode*>
class Solution {
public:
    P LCA(TreeNode* root) {
        if(root == NULL) return {0, NULL};

        P leftAns = LCA(root->left);
        P rightAns = LCA(root->right);

        if(leftAns.first == rightAns.first) return {leftAns.first + 1, root};

        else if(leftAns.first > rightAns.first) return {leftAns.first + 1, leftAns.second};

        return { rightAns.first + 1, rightAns.second};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return LCA(root).second;
    }
};