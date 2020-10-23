// void dfs(int u, vector<int>& adj1, bool vis[]){
//     visited[u]=true;
//     for(int i=0; i<adj1[u].size(); i++){
//         if(!visited[adj[u][i]])
//             dfs(adj1[u][i], adj1);
//     }
// }

int Solution::solve(int A, vector<vector<int> > &B) {
    
    vector<int> adj[A+1];
    bool vis[A+1];
    memset(vis, false, sizeof(vis));
    int par[A+1];
    memset(par, -1, sizeof(vis));
    
    for(int i=0; i<B.size(); i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    stack<int> s;
    
    for(int i=1; i<=A; i++){
        if(!vis[i])
            s.push(i);
        while(!s.empty()){
            int u=s.top();
            vis[u]=true;
            s.pop();
            for(int i=0; i<adj[u].size(); i++){
                if(!vis[adj[u][i]]){
                    s.push(adj[u][i]);
                    par[adj[u][i]]=u;
                }
                else{
                    if(par[u]!=adj[u][i])
                        return true;
                }
            }
        }
    }
    return false;
}
