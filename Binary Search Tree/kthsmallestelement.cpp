//https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    int kthSmallest(TreeNode* root, int k) {
        
        vector<int> v;
        
        queue<TreeNode *> q;
        if(root==NULL){
            return 0;
        }
        
        q.push(root);
        
        while(!q.empty()){
            TreeNode *temp=q.front();
            v.push_back(temp->val);
            q.pop();
            
            
            if(temp->left){
                q.push(temp->left);
            }
            
            if(temp->right){
                q.push(temp->right);
            }
        }
        
        sort(v.begin(),v.end());
        
        if(k>v.size()){
            return 0;
        }else{
            return v[k-1];
        }
        
    }
};