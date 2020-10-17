/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int traverse(TreeNode* root, bool& flag1){
    if(root==NULL)
        return 0;
    int ldepth=traverse(root->left, flag1);
    int rdepth=traverse(root->right, flag1);
    if(abs(ldepth-rdepth)>1){
        flag1=false;
    }
    return max(ldepth, rdepth)+1;
} 
 
int Solution::isBalanced(TreeNode* A) {
    bool flag=true;
    int exvar=traverse(A, flag);
    if(flag==false)
        return 0;
    else
        return 1;
        
}
