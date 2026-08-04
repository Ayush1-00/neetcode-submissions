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
    void solve(TreeNode* root,vector<int>&ans){
        if(root==NULL)return;
        ans.push_back(root->val);
        if(root->right)solve(root->right,ans);
        else solve(root->left,ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            TreeNode* temp=NULL;
            for(int i=0;i<n;i++){
                TreeNode* fro=q.front();
                q.pop();
                if(fro->left)q.push(fro->left);
                if(fro->right)q.push(fro->right);
                temp=fro;
            }
            ans.push_back(temp->val);
        }
        return ans;
    }
};
