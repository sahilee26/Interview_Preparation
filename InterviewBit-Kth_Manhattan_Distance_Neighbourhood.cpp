// int max4(int a, int b, int c, int d){
//     return max(a, max(b, max(c, d)));
// }


vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    int n=B.size();
    int m=B[0].size();
    vector<vector<int> > ans(n, vector<int> (m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ans[i][j]=B[i][j];
        }
    }
    
    int dp[n][m][A+1];
     for(int k=0; k<=A; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                    dp[i][j][k]=B[i][j];
                if(k!=0){
                    if(i>=1)
                        dp[i][j][k]=max(dp[i][j][k], dp[i-1][j][k-1]);
                    if(j>=1)
                        dp[i][j][k]=max(dp[i][j][k], dp[i][j-1][k-1]);
                    if(i<n-1)
                        dp[i][j][k]=max(dp[i][j][k], dp[i+1][j][k-1]);
                    if(j<m-1)
                        dp[i][j][k]=max(dp[i][j][k], dp[i][j+1][k-1]);
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ans[i][j]=dp[i][j][A];    
        }
    }
    return ans;
}
