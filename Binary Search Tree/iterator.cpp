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
class BSTIterator {
public:
    queue<int> temp;
    BSTIterator(TreeNode* root) {
        dfs(root,temp);
    }
    
    void dfs(TreeNode *root,queue<int> &temp){
        if(root==NULL){
            return;
        }
        dfs(root->left,temp);
        temp.push(root->val);
        dfs(root->right,temp);
    }
    
    /** @return the next smallest number */
    int next() {
        int value=temp.front();
        temp.pop();
        return value;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return temp.size()>0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */