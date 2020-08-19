int Solution::numTrees(int A) {
    int dp[A+1];
    memset(dp, 0, sizeof(dp));
    dp[0]=1;
    for(int i=1; i<=A; i++){
        for(int j=0; j<=i-1; j++){
            dp[i]+=(dp[j]*dp[i-j-1]);
        }
    }
    return dp[A];
}
