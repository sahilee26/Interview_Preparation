
int Solution::minCut(string A) {
    int len=A.length();
    int dp[len][len];
    int ans[len][len];

    for(int i=0; i<len; i++)
        dp[i][i]=1;
    for(int i=0; i<len-1; i++){
        if(A[i]==A[i+1])
            dp[i][i+1]=1;
        else
            dp[i][i+1]=0;
    }
    for(int i=2; i<len; i++){
        for(int j=0; j+i<len; j++){
            int k=j+i;
            if(A[j]==A[k] && dp[j+1][k-1]==1)
                dp[j][k]=1;
            else
                dp[j][k]=0;
        }
    }
    for(int l=0; l<len; l++){
        for(int i=0; i+l<len; i++){
            int j=i+l;
            if(dp[i][j]==1){
                ans[i][j]=0;
                continue;
            }
            ans[i][j]=1e9;
            for(int k=i; k<j; k++){
                ans[i][j] = min(ans[i][j], ans[i][k]+1+ans[k+1][j]);
            }
        }
    }
    return ans[0][len-1];
}
