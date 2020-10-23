int Solution::solve(int A, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E) {
    if(C==D)
        return 0;
        
    vector<vector<pair<int, int> > >X(A+1);
    
    int ans=INT_MAX;
    
    for(int i=0; i<B.size(); i++){
        X[B[i][0]].push_back({B[i][1], B[i][2]});
        X[B[i][1]].push_back({B[i][0], B[i][2]});
    }
    int dist[A+1];
    vector<vector<pair<int, int> > > Y;
    for(int i=0; i<E.size(); i++){
        
        if(E[i][0]>A || E[i][1]>A){
            continue;
        }
        Y=X;
        Y[E[i][0]].push_back({E[i][1], E[i][2]});
        Y[E[i][1]].push_back({E[i][0], E[i][2]});
        
        int vis[A+1];
        
        for(int i=0; i<=A; i++){
            dist[i]=INT_MAX;
            vis[i]=0;
        }
        dist[C]=0;
        multiset<pair<int, int> >pq;
        pq.insert({0, C});
        
        while(!pq.empty()){
            pair<int, int> p1=*pq.begin();
            pq.erase(pq.begin());
            int u=p1.second;
            if(vis[u])
                continue;
            vis[u]=true;
            for(int j=0; j<Y[u].size(); j++){
                int wgt=Y[u][j].second;
                int v=Y[u][j].first;
                
                if(dist[v]>dist[u]+wgt){
                    dist[v]=dist[u]+wgt;
                    pq.insert({dist[v], v});
                }
            }
        }
        ans=min(ans, dist[D]);
    }
    if(ans==INT_MAX)
        return -1;
    return ans;
}
