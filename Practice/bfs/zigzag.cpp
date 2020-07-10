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
        
        vector<vector<int> > result;
        if(!root){
            return result;
        }
        
        queue<TreeNode *> q;
        
        q.push(root);
        
        bool leftorright=true;
        
        while(!q.empty()){
            int n=q.size();
            
            vector<int> v(n);
            
            for(int i=0;i<n;i++){
                TreeNode *temp=q.front();
                q.pop();
                
                if(leftorright){
                    v[i]=temp->val;
                }else{
                    v[n-i-1]=temp->val;
                }
                
                if(temp->left){
                    q.push(temp->left);
                }
                
                if(temp->right){
                    q.push(temp->right);
                }
                    
                    
            }
            leftorright=!leftorright;
            result.push_back(v);
        }
        
        
        return result;
    }
};