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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> res;
        
        queue<TreeNode *>q;
        
        if(root==NULL){
            return res;
        }
        
        q.push(root);
        
        while(!q.empty()){
            int n=q.size();
            vector<int> v;
            for(int i=0;i<n;i++){
                TreeNode *temp=q.front();
                q.pop();
                
                v.push_back(temp->val);
                
                if(temp->left){
                    q.push(temp->left);
                }
                
                
                if(temp->right){
                    q.push(temp->right);
                }
            }
            res.push_back(v.back());
        }
        return res;
        
    }
};