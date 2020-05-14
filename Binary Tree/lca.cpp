/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    bool findPath(vector<TreeNode*> &path,TreeNode *root,TreeNode *temp){
        if(root==NULL){
            return false;
        }
        
        path.push_back(root);
        if(root==temp){
            return true;
        }
        
        if((root->left && findPath(path,root->left,temp))||(root->right && findPath(path,root->right,temp))){
            return true;
        }
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        
        vector<TreeNode*> p1,q1;
        
        
        if(!findPath(p1,root,p)||!findPath(q1,root,q)){
            return NULL;
        }
        
        int i;
        for(i=0;i<p1.size() && i<q1.size();i++){
            //cout<<p1[i]->val<<" "<<q1[i]->val;
            cout<<endl;
            if(p1[i]!=q1[i]){
                break;
            }
        }
        //cout<<i<<endl;
        
        return q1[i-1];
        
    }
};