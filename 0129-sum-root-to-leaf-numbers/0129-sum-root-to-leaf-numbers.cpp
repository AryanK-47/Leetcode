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
    void fun(TreeNode*root, int sum , int& res){
        if(root==nullptr)return ;
        sum=sum*10+root->val;

        if(root->left==nullptr && root->right==nullptr){
            res+=sum;
            return;
            
        }
       fun(root->left,sum,res);
       fun(root->right,sum,res);     
        
    }

    int sumNumbers(TreeNode* root) {
        int t=0;
        fun(root,0,t);
        return t;
        
    }
};