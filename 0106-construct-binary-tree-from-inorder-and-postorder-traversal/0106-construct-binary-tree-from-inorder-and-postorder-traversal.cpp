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
    int Pre=0;
    TreeNode*fun( vector<int>& inorder,vector<int>& postorder,int left,int right){
        if(left>right)return nullptr;

        int rootval=postorder[Pre--];
        TreeNode*root= new TreeNode(rootval);

        int index=left;

        while(inorder[index]!=rootval){
            index++;
        }
        root->right=fun(inorder,postorder,index+1,right);

        root->left=fun(inorder,postorder,left,index-1);
    
    return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        Pre = postorder.size() - 1;

        return fun(inorder, postorder,
                   0, inorder.size() - 1);
    }
};