int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    int m=min(n, B);
    
    int prof[m+1][n+1];
    // dp[i][j] stores maximum profit that can be achieved by using prices atmost i transactions
    // and jth day
    
    for(int i=0; i<=m; i++){
        // no profit can be made on 0th day and 1st day
        prof[i][0]=0;
        prof[i][1]=0;
    }
    for(int i=0; i<=n; i++){
        // no profit can be made in 0 atmost transactions
        prof[0][i]=0;
    }
   
    for(int i=1; i<=m; i++){
        int prev_diff=-1e9;
        for(int j=1; j<=n; j++){
            prev_diff=max(prev_diff, prof[i-1][j-1]-A[j-1]);
            prof[i][j]=-1e9;
            // for(int k=0; k<j; k++){
            //     prof[i][j] = max(prof[i][j], prof[i-1][k]-A[k]+A[j-1]);
            // }
            prof[i][j] = max(prof[i][j], prev_diff + A[j-1]);
            prof[i][j]=max(prof[i][j], prof[i][j-1]);
        }
    }
    return prof[m][n];
    
}
