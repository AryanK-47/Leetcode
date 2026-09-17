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
    bool fun(TreeNode*root,bool& ans,TreeNode*&check){
        if(root==nullptr)return true;
        fun(root->left,ans,check);
        if(check==nullptr){
            check=root;
        }
        else{
            if(check->val>=root->val)ans=false;
            check=root;
        }
        fun(root->right,ans,check);
        return ans;
    }
    bool isValidBST(TreeNode* root) {
        bool ans=true;
        TreeNode*check=nullptr;
        fun(root,ans,check);
        return ans;


        
    
    }
};