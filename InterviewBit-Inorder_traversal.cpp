/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void traverse(TreeNode* root, vector<int>& v){
    if(root==NULL)
        return;
        
    traverse(root->left, v);
    v.push_back(root->val);
    traverse(root->right, v);
    
    return ;
} 
 
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> v;
    traverse(A, v);
    return v;
}
