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
    void leftpush(TreeNode*node,stack<TreeNode*>&st){
        while(node){
            st.push(node);
            node=node->left;
        }
    }
    void rightpush(TreeNode*node,stack<TreeNode*>&st){
        while(node){
            st.push(node);
            node=node->right;
        }
    }
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*>leftStack;
        stack<TreeNode*>rightStack;

        leftpush(root,leftStack);
        rightpush(root,rightStack);

        while( !leftStack.empty() && !rightStack.empty()){
            TreeNode*left=leftStack.top();
            TreeNode*right=rightStack.top();

            if(left==right)break;

            int sum=left->val+right->val;
            if(sum==k)return true;
            else if(sum<k){
                leftStack.pop();
                leftpush(left->right,leftStack);
            }
            else{
                rightStack.pop();
                rightpush(right->left,rightStack);
            }
        }
        return false;
    }
};