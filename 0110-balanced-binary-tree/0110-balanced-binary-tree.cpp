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

class Pair{
    public: 
        int height;
        bool isBalanced;

        Pair(int height, bool isBalanced) {
            this->height = height;
            this->isBalanced = isBalanced;
        }
};

class Solution {
public:
    Pair* f(TreeNode* root) {
        if(root == NULL) {
            return new Pair(0,true);
        }

        Pair* left = f(root->left);
        Pair* right = f(root->right);

        bool isBalanced = abs(left->height - right->height)<=1 && left->isBalanced && right->isBalanced;
        int height = 1 + max(left->height, right->height);

        return new Pair(height, isBalanced);
    }
    bool isBalanced(TreeNode* root) {
        Pair* p = f(root);
        return p->isBalanced;
    }
};