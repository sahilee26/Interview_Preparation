/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int height(TreeNode* root){
    if(root==NULL)
        return INT_MAX;
    else if(!root->left && !root->right)
        return 1;
    else
        return (min(height(root->left), height(root->right))+1);
}
 
int Solution::minDepth(TreeNode* A) {
    return height(A);   
}
