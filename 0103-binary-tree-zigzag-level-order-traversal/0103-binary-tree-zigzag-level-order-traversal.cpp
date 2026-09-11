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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);

        if(root == nullptr)
            return ans;

        bool leftright=true;

        while(!q.empty()){
            int lvlsize=q.size();
            vector<int>temp;
            while(lvlsize--){
                TreeNode* t=q.front();
                q.pop();
                
                temp.push_back(t->val);
                if(t->left!=nullptr)q.push(t->left);
                if(t->right!=nullptr)q.push(t->right);
            }
            if(!leftright)reverse(temp.begin(),temp.end());

            ans.push_back(temp);
            leftright=!leftright;
        }
        return ans;
    }
};