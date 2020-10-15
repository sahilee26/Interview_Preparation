/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 

bool traverse(TreeNode* root, vector<int>& path, int D){
    if(root == NULL)
        return false;
        
    path.push_back(root->val);
    
    if(root->val==D)
        return true;
    if((root->left && traverse(root->left, path, D))|| 
        (root->right && traverse(root->right, path, D)))
        return true;
        
    path.pop_back();
    return false;
}


int Solution::lca(TreeNode* A, int B, int C) {
    vector<int> path1, path2;

    if(!traverse(A, path1, B) || !traverse(A, path2, C))
        return -1;
    else{
        int i=0;
        for(; i<path1.size() && i<path2.size(); i++){
            if(path1[i]!=path2[i]){
                break;
            }
        }
        return path1[i-1];
    }
}
