vector<pair<int, int> >v;
#define mp make_pair
#define ff first
#define se second
#define pb push_back

int Solution::knight(int A, int B, int C, int D, int E, int F) {

    v.pb(mp(2, 1));
    v.pb(mp(1, 2));
    v.pb(mp(-2, 1));
    v.pb(mp(1, -2));
    v.pb(mp(-1, 2));
    v.pb(mp(2, -1));
    v.pb(mp(-2, -1));
    v.pb(mp(-1, -2));
    
    bool visited[A][B];
    int level[A][B];
    memset(level , 0, sizeof(level));    
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> que;
    que.push(mp(C-1, D-1));
    visited[C-1][D-1]=true;

    while(!que.empty()){
        pair<int, int> p1=que.front();
        que.pop();
        int flag=0;
        for(int i=0; i<v.size(); i++){
            int x1=p1.ff+v[i].ff;
            int y1=p1.se+v[i].se;
            if(!visited[x1][y1] && x1>=0 && y1>=0 && x1<A && y1<B){
                que.push(mp(x1, y1));
                visited[x1][y1]=true;
                level[x1][y1]=level[p1.ff][p1.se]+1;
            }
            if(x1==E-1 && y1==F-1){
                flag=1;
                break;
            }
        }
        if(flag==1)
            break;
    }
    if(visited[E-1][F-1])
        return level[E-1][F-1];
    else 
        return -1;
}
