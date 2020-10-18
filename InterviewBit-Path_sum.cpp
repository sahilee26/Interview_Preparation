/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int isPossible(TreeNode* root, int sum){
    if(root->left!=NULL && root->right!=NULL) 
        return (isPossible(root->left, sum-(root->val)) || isPossible(root->right, sum-(root->val)));
    if(root->left!=NULL)
        return isPossible(root->left, sum-(root->val));
    else if(root->right!=NULL)
        return isPossible(root->right, sum-(root->val));
    else if(sum==0)
        return 1;
    else
        return 0;
} 
 
int Solution::hasPathSum(TreeNode* A, int B) {
    return isPossible(A, B);
}

