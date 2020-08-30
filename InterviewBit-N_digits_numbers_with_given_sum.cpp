int mod=1e9+7;

int Solution::solve(int A, int B) {
    swap(A, B);
    long long int dp[A+1][B+1];
    for(int i=0; i<=A; i++){
        for(int j=0; j<=B; j++){
            dp[i][j]=0;
        }
    }
    dp[0][0]=1;
    for(int i=1; i<=A; i++){
        for(int j=1; j<=B; j++){
            if(j==1){
                for(int k=1; k<=9; k++){
                    if(i>=k){
                        dp[i][j]=dp[i][j]%mod +dp[i-k][j-1]%mod;
                        dp[i][j]%=mod;
                    }
                }
            }
            else{
                for(int k=0; k<=9; k++){
                    if(i>=k){
                        dp[i][j]=dp[i][j]%mod +dp[i-k][j-1]%mod;
                        dp[i][j]%=mod;
                    }
                }
            }
        }
    }
    return dp[A][B];
}
