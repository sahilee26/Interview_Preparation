int mod=1000007;
int Solution::coinchange2(vector<int> &A, int B) {
    int n=A.size();
    int dp[B+1][n]={0};
    for(int i=0; i<n; i++){
        dp[0][i]=1;
    }
    for(int i=1; i<=B; i++){
        for(int j=0; j<n; j++){
            if(i>=A[j])
                dp[i][j]+=(dp[i-A[j]][j])%mod;
            dp[i][j]%=mod;
            if(j>0)
                dp[i][j]+=(dp[i][j-1])%mod;
            dp[i][j]%=mod;
        }
    }
    dp[B][n-1]%=mod;
    return dp[B][n-1];
    
}
