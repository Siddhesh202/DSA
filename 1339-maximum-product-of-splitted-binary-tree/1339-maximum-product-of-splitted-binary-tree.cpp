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
#define ll long long
#define MOD 1000000007
class Solution {
public:
    ll treeSum = 0, ans = LLONG_MIN;
    void getTotalTreeSum(TreeNode* root) {
        if(root == NULL) return;

        treeSum += root->val;
        getTotalTreeSum(root->left);
        getTotalTreeSum(root->right);
    }

    int getSumUnder(TreeNode* root) {
        if(root == NULL) return 0;

        ll lSum = getSumUnder(root->left);
        ll rSum = getSumUnder(root->right);

        ans = max({ans, (treeSum - lSum) * lSum, (treeSum - rSum) * rSum});
        return lSum + rSum + root->val;
    }

    int maxProduct(TreeNode* root) {
        getTotalTreeSum(root);
        getSumUnder(root);
        return ans % MOD;
    }
};