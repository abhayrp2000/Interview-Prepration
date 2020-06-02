//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
    bool findTarget(TreeNode* root, int k) {
        
        vector<int> v;
        
        queue<TreeNode *> q;
        if(root==NULL){
            return false;
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
        
        map<int,int> mp;
        
        for(auto val:v){
            int diff=k-val;
            if(mp.find(diff)!=mp.end()){
                return true;
            }else{
                mp.insert(make_pair(val,1));
            }
        }
        return false;
        
    }
};