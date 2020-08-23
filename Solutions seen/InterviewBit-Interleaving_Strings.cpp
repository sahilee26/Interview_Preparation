bool dp[200][200];
// dp[i][j] stores if we can build string C[0....i+j-1] using A[0...i-1] ans B[0...j-1]


int Solution::isInterleave(string A, string B, string C) {
    int n=A.length();
    int m=B.length();
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            dp[i][j]=false;
        }
    }
    dp[0][0]=true;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i>0 && A[i-1]==C[i+j-1] && dp[i-1][j])
                dp[i][j]= true;
            if(j>0 && B[j-1]==C[i+j-1] && dp[i][j-1])
                dp[i][j]= true;
        }
    }
    return dp[n][m];
}
