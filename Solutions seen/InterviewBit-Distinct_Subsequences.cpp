int dp[1000][1000];

int distsubs(string S,string T, int n, int m){
    if(dp[n+1][m+1]!=-1)
        return dp[n+1][m+1];
    int ans=0;
    ans+= distsubs(S, T, n-1, m);
    if(S[n]==T[m]){
        ans+=distsubs(S, T, n-1, m-1);
    }
    return dp[n+1][m+1]=ans;
}

int Solution::numDistinct(string S, string T) {
    int n=S.length();
    int m=T.length();
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            dp[i][j]=-1;
        }
    }
    for(int i=0; i<=m; i++){
        dp[0][i]=0;
    }
        for(int i=0; i<=n; i++){
        dp[i][0]=1;
    }
    return distsubs(S, T, n-1, m-1);
}
