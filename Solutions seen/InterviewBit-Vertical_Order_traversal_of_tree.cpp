/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    
    vector<vector<int> > v;
    
    queue<pair<TreeNode*, int >> q;
    q.push({A, 0});
    
    map<int ,vector<int> > mp;
    
    while(!q.empty()){
        pair<TreeNode* ,int> p=q.front();
        q.pop();
        if(p.first->left!=NULL)
            q.push({p.first->left, p.second-1});
        if(p.first->right!=NULL)
            q.push({p.first->right, p.second+1});
        
        mp[p.second].push_back(p.first->val);
    }
    for(auto it=mp.begin(); it!=mp.end(); it++){
        v.push_back(it->second);
    }
    return v;
}
