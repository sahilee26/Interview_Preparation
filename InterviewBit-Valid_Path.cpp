string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    
    int x1[8]={-1, -1, -1, 0, 0, 1, 1, 1};
    int y1[8]={1, -1, 0, -1, 1, -1, 0, 1};
    
    map<pair<int, int>, int> vis;
    for(int i=0; i<E.size(); i++){
        int cenx=E[i];
        int ceny=F[i];
        for(int i=0; i<=A; i++){
            for(int j=0; j<=B; j++){
                if (sqrt((i-cenx)*(j-cenx)+(i-ceny)*(j-ceny))<=D)
                    vis[{i, j}]=1;
            }
        }
    }
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    
    while(!q.empty()){
        pair<int, int> p1=q.front();
        q.pop();
        if(vis[{p1.first, p1.second}]==1)
            continue;
        vis[{p1.first, p1.second}]=1;
        if(p1.first==A && p1.second==B)
            return "YES";
        for(int i=0; i<8; i++){
            if(p1.first+x1[i]>=0 && p1.first+x1[i]<=A && p1.second+y1[i]>=0 && p1.second+y1[i]<=B)
                if(vis[{p1.first+x1[i], p1.second+y1[i]}]!=1)
                    q.push({p1.first+x1[i], p1.second+y1[i]});
       }
    }
    return "NO";
}
