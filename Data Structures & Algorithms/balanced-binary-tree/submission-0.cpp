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
    pair<int,bool> solve(TreeNode* root){
        if(root==NULL)return {0,true};
        if(root->left==NULL&&root->right==NULL)return {1,true};
        pair<int,bool>left=solve(root->left);
        pair<int,bool>right=solve(root->right);
        int h=max(left.first,right.first)+1;
        bool check=abs(left.first-right.first)<=1;
        bool flag=(check&&left.second)&&right.second;
        return {h,flag};
    }
public:
    bool isBalanced(TreeNode* root) {
        return solve(root).second;
    }
};
