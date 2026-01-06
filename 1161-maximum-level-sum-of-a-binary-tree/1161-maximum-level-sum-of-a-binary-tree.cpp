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
    int maxLevelSum(TreeNode* root) {
        int currLvl = 1, ans, maxiSum = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            int currLvlSum = 0;

            for(int i = 0; i < size; i++) {
                TreeNode* currNode = q.front();
                q.pop();
                currLvlSum += currNode->val;

                if(currNode->left != NULL) q.push(currNode->left);
                if(currNode->right != NULL) q.push(currNode->right);
            }

            // cout << "level : " << currLvl << ", sum : " << currLvlSum << endl;
            if(currLvlSum > maxiSum) {
                maxiSum = currLvlSum;
                ans = currLvl;
            }

            currLvl++;
        }

        return ans;
    }
};