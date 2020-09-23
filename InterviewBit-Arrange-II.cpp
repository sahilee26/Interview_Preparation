int dp[1005][1005];
int rec(string A, int i, int n, int stable, int B){
    if(stable>B || i>=n)
        return 1e9;
    if(dp[i][stable-1]!=-1)
        return dp[i][stable-1];
    int cost=1e9;
    int white=0, black=0;
    for(int j=i; j<n; j++){
        if(A[j]=='W')
            white++;
        else if(A[j]=='B')
            black++;
        if(j+1<n && stable<B)
            cost=min(cost, black*white + rec(A, j+1, n, stable+1, B));
        else if(j==n-1 && stable==B)
            cost=min(cost, black*white);
    }
    dp[i][stable-1]=cost;
    return dp[i][stable-1];
}


int Solution::arrange(string A, int B) {
    int n=A.length();
    if(n<B)
        return -1;
    memset(dp, -1, sizeof(dp));
    return rec(A, 0, n,  1, B);
}
