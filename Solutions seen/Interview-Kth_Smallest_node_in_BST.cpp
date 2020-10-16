/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* traverse(TreeNode* root, int& count){
    if(root==NULL)
        return NULL;
    TreeNode* left=traverse(root->left, count);
    if(left!=NULL)
        return left;
    count--;
    if(count==0)
        return root;
    return traverse(root->right, count);
} 
 
int Solution::kthsmallest(TreeNode* A, int B) {
    TreeNode* ans=traverse(A, B); 
    return ans->val;
}
