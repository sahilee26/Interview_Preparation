bool dp[200][200][200];

int Solution::isInterleave(string A, string B, string C) {
    int n=A.length();
    int m=B.length();
    int p=C.length();
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            for(int k=0; k<=p; k++){
                dp[i][j][k]=false;
            }
        }
    }
    for(int i=0; i<=p; i++){
        dp[0][0][i]=false;
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            dp[i][j][0]=true;
        }
    }
    
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            for(int k=1; k<=p; k++){
                if(i>0 && A[i-1]==C[k-1] && dp[i-1][j][k-1] )
                    dp[i][j][k]= true;
                if(j>0 && B[j-1]==C[k-1] && dp[i][j-1][k-1])
                    dp[i][j][k]= true;
                           
            }
        }
    }
    return dp[n][m][p];
}
