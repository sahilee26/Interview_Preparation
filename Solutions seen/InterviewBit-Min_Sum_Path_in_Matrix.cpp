int Solution::minPathSum(vector<vector<int> > &A) {
    int m=A.size(),n= A[0].size();
    int dp[m][n]={0};
    int sum1=0;
    for(int i=0; i<m; i++){
        sum1+=A[i][0];
        dp[i][0]=sum1;
    }
    sum1=0;
    for(int j=0; j<n; j++){
        sum1+=A[0][j];
        dp[0][j]=sum1;
    }
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            dp[i][j]=A[i][j]+ min(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[m-1][n-1];
}

