int rnk[100001];
int par[100001];

bool comp(vector<int> a1, vector<int> b1){
    return a1[2]<b1[2];
}

int find(int u){
    if(par[u]!=u)
        par[u]=find(par[u]);
    return par[u];
}

void Union(int x1, int y1){
    int xset = find(x1);
    int yset = find(y1);
    if(rnk[xset]>rnk[yset]){
        par[yset]=xset;
    }
    else if(rnk[yset]>rnk[xset]){
        par[xset]=yset;
    }
    else{
        rnk[xset]++;
        par[yset]=xset;
    }
}

int Solution::solve(int A, vector<vector<int> > &B) {
   sort(B.begin(), B.end(), comp);
   int i=0, j=0;
   int cost=0;
   for(int i=0; i<100001; i++)
        par[i]=i;
   // i denote edges and j denote no. of edges in spaning tree
   while(j<A-1 && i<B.size()){
       int x=find(B[i][0]);
       int y=find(B[i][1]);
      
       if(x!=y){
           cost+=B[i][2];
           j++;
           Union(x, y);
       }
       i++;
   }
    return cost;
}
