//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
        
        vector<vector<int> > v;
        
        queue<TreeNode *> q;
        
        if(root==NULL){
            return v;
        }
        
        q.push(root);
        
        while(!q.empty()){
            int count=q.size();
            vector<int> temp;
            
            while(count>0){
                TreeNode *t=q.front();
                temp.push_back(t->val);
                q.pop();
                
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
                count--;
            }
            v.push_back(temp);
        }
        
        for(int i=0;i<v.size();i++){
            if(i%2!=0){
                reverse(v[i].begin(),v[i].end());
            }
        }
        
        return v;
        
    }
};