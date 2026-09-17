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
    void fun(TreeNode*root, vector<vector<int>>&ans,vector<int>&temp, int sum,int t){

        if(root==nullptr)return ;
        sum=sum+root->val;

        temp.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr){
            if(sum==t){
                ans.push_back(temp);
            }
        }
        fun(root->left,ans,temp,sum,t);
        fun(root->right,ans,temp,sum,t);

        sum-=root->val;
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        fun(root,ans,temp,0,targetSum);
        return ans;

    }
};