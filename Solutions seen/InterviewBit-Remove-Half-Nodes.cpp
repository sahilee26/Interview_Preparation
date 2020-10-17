/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// TreeNode* traverse(TreeNode* root){
//     if(root->left==NULL && root->right==NULL)
//         return;
//     traverse(root->left);
//     TreeNode* left1=root->left;
//     TreeNode* right1=root->right;
    
//     if(left1->left==NULL && left1->right!=NULL){
//         root->left=left1-right;
//         left1->right=NULL;
//     }
//     if(left1->left!=NULL && left1->right==NULL){
//         root->left=left1-left;
//         left1->left=NULL;
//     }
//     if(right1->left==NULL && right1->right!=NULL){
//         root->left=right1-right;
//         right1->right=NULL;
//     }
//     if(right1->left!=NULL && right1->right==NULL){
//         root->left=right1-left;
//         right1->left=NULL;
//     }
//     traverse(root->right);
    
// } 
 
TreeNode* traverse(TreeNode* A){
    if(A==NULL)
        return NULL;
    A->left=traverse(A->left);
    A->right=traverse(A->right);
    if(A->left==NULL && A->right==NULL)
        return A;
    if(A->left==NULL){
        TreeNode* node = A->right;
        free(A);
        return node;
    }
    else if(A->right==NULL){
        TreeNode* node = A->left;
        free(A);
        return node;
    }
    return A;
}
 
TreeNode* Solution::solve(TreeNode* A) {
    return traverse(A);
}
