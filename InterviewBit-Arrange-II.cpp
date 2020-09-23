int rec(string A, vector<vector<int>>dp, int i, int n, int stable, int B){
    if(stable>B || i>=n)
        return INT_MAX;
    if(dp[i][stable-1]!=-1)
        return dp[i][stable-1];
    int cost=INT_MAX;
    int white=0, black=0;
    for(int j=i; j<n; j++){
        if(A[j]=='W')
            white++;
        else if(A[j]=='B')
            black++;
        if(j+1<n && stable<B)
            cost=min(cost, black*white + rec(A, dp, j+1, n, stable+1, B));
        else if(j==n-1 && stable==B)
            cost=min(cost, black*white);
    }
    dp[i][stable-1]=cost;
    return dp[i][stable-1];
}


int Solution::arrange(string A, int B) {
    int n=A.length();
    vector<vector<int> > dp (n,vector<int>(B, -1));
    return rec(A, dp, 0, n,  1, B);
}
