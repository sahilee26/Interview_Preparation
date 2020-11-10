bool dfs(int u, vector<int> adj[], bool vis[], bool recStack[]){
    if(!vis[u]){
        vis[u]=true;
        recStack[u]=true;
        for(int i=0; i<adj[u].size(); i++){
            if(!vis[adj[u][i]]){
                if(dfs(adj[u][i], adj, vis, recStack))
                    return true;
            }
            else if(recStack[adj[u][i]])
                return true;
        }
    }
    recStack[u]=false;
    return false;
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    
    vector<int> adj[100005];
    bool vis[100005];
    bool recStack[100005];
    for(int i=0; i<=A; i++){
        vis[i]=false;
    }
    for(int i=0; i<B.size(); i++){
        adj[B[i]].push_back(C[i]);
    }
    
    memset(vis, false, sizeof(vis));
    memset(recStack, false, sizeof(recStack));
    for(int i=1; i<=A; i++){
        if(dfs(i, adj, vis, recStack))
            return false;
    }
    return true;
}
