class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int len=graph.size();
        queue<int> q;
        q.push(0);
        bool vis[len];
        int color[len];
        memset(vis, false, sizeof(vis));
        memset(color, -1, sizeof(color));
        color[0]=1;
        for(int i=0; i<len; i++){
            q.push(i);
            while(!q.empty()){
                int u=q.front();
                q.pop();
                if(vis[u])
                    continue;
                vis[u]=true;
                for(int i=0; i<graph[u].size(); i++){
                    if(!vis[graph[u][i]] && color[graph[u][i]]==-1){
                        q.push(graph[u][i]);
                        color[graph[u][i]]=1-color[u];
                    }
                    else if(color[graph[u][i]]==color[u]){
                       return false;
                    }
                }
            }
        }
        return true;
    }
};
