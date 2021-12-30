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
    vector<int>inorder;
    int idx;
    
    void traverse(TreeNode * root,vector<int> &v){
        if(root == NULL){
            return;
        }
        traverse(root->left,v);
        v.push_back(root->val);
        traverse(root->right,v);
    }
    
    BSTIterator(TreeNode* root) {
        traverse(root,inorder);
        idx = -1;
    }
    
    int next() {
        idx++;
        return inorder[idx];
    }
    
    bool hasNext() {
        return idx != inorder.size() - 1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */