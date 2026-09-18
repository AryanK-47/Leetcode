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
    TreeNode*fun(vector<int>& preorder, vector<int>& inorder,int left,int right){
        if(left>right)return nullptr;

        int rootval=preorder[Pre++];
        TreeNode*root= new TreeNode(rootval);

        int index=left;

        while(inorder[index]!=rootval){
            index++;
        }
    root->left=fun(preorder,inorder,left,index-1);
    root->right=fun(preorder,inorder,index+1,right);

    return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return fun(preorder,inorder,0,inorder.size()-1);
    }
};