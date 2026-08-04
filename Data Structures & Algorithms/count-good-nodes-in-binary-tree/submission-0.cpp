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
    void solve(TreeNode* root,int maxi,int&count){
        if(root==NULL)return;
        if(maxi<=root->val){
            count++;
            maxi=root->val;
        }
        solve(root->left,maxi,count);
        solve(root->right,maxi,count);
    }
public:
    int goodNodes(TreeNode* root) {
        int count=0;
        solve(root,INT_MIN,count);
        return count;
    }
};
