int Solution::solve(vector<vector<int> > &A) {
    int m=A.size();
    int n=A[0].size();
    int hist[m][n];
    memset(hist, sizeof(hist), 0);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0)
                hist[i][j]=A[i][j];
            else if(A[i][j]==1)
                hist[i][j]=hist[i-1][j]+1;
            else
                hist[i][j]=0;
        }
    }
    int ans=INT_MIN;
    for(int i=0; i<m; i++){
        sort(hist[i], hist[i]+n);
        int maxrow=hist[i][0]*n;
        for(int j=0; j<n; j++){
                maxrow=max(maxrow, hist[i][j]*(n-j));
        }
        ans=max(ans, maxrow);
    }
    return ans;
}
