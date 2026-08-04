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
    pair<int,int> solve(TreeNode* root){
        if(root==NULL)return {0,0};
        if(root->left==NULL&&root->right==NULL)return {1,1};
        pair<int,int>left=solve(root->left);
        pair<int,int>right=solve(root->right);
        int h=max(left.second,right.second)+1;
        int d=max(max(left.first,right.first),left.second+right.second+1);
        return {d,h};
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        return solve(root).first-1;
    }
};
