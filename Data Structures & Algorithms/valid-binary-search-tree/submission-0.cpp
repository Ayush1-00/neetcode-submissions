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
    bool solve(TreeNode* root,int mini,int maxi){
        if(root==NULL)return true;
        
        if(root->val>=maxi||root->val<=mini)return false;
        if(root->left==NULL&&root->right==NULL)return true;
        bool left=solve(root->left,mini,root->val);
        bool right=solve(root->right,root->val,maxi);
        return left&&right;
    }
public:
    bool isValidBST(TreeNode* root) {
        return solve(root,INT_MIN,INT_MAX);
    }
};
