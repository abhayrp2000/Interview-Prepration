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
    
    void find_paths(TreeNode *root,int sum,vector<int> &path,vector<vector<int>> &paths){
        if(root==NULL){
            return;
        }
        path.push_back(root->val);
        if(root->val==sum && root->left==NULL && root->right==NULL){
            paths.push_back(path);
        }
        
        find_paths(root->left,sum-root->val,path,paths);
        find_paths(root->right,sum-root->val,path,paths);
        path.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > paths;
        vector<int> path;
        
        find_paths(root,sum,path,paths);
        return paths;
    }
};