/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> res;
    
    queue<pair<TreeNode*, int > > q;
    q.push({A, 0});
    
    map<int ,vector<int> > mp;
    
    while(!q.empty()){
        pair<TreeNode* ,int> p=q.front();
        q.pop();
        
        if(p.first->left){
            if(!p.first->right || p.first->right->val!=B)
                q.push({p.first->left, p.second+1});
        }
        if(p.first->right){
            if(!p.first->left || p.first->left->val!=B)
                q.push({p.first->right, p.second});
        }
        mp[p.second].push_back(p.first->val);
    }
    
    for(auto it=mp.begin(); it!=mp.end(); it++){
        int flag=0;
        for(int i=0; i<it->second.size(); i++){
            if(it->second[i]==B)
                flag=1;
        }
        if(flag==1){
            for(int i=0; i<it->second.size(); i++){
                if(it->second[i]!=B)
                    res.push_back(it->second[i]);
            }
        }
    }
    return res;
}
