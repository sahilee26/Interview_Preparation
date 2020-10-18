/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    
    vector<int> res;
    
    if(A==NULL)
        return res;
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()){
        TreeNode* p=q.front();
        q.pop();
        
        res.push_back(p->val);
        if(p->left)
            q.push(p->left);
        
        while(p->right){
            p=p->right;
            res.push_back(p->val);
            if(p->left)
                q.push(p->left);
        }
    }
    return res;
}
