int Solution::canJump(vector<int> &A) {
    int len=A.size();
    int dp[1000005];
    memset(dp, 0, sizeof(dp));
    dp[0]=1;
    for(int i=0; i<len; i++){
        if(dp[i]==1){
            for(int j=1; j<=A[i]; j++)
                dp[i+j]=1;
        }
        else
            continue;
    }
    return dp[len-1];
}
