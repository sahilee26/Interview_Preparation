int mindist(string A, string B, int n, int m, vector<vector<int> >& dist){
    if(m<=0)
        return dist[n][m]=n;
    if(dist[n][m]!=-1)
        return dist[n][m];
    else{
        int ans=1e12;
        if(m>0 && n>0 && A[n-1]==B[m-1])
            ans=min(ans, mindist(A, B, n-1, m-1, dist));
        else{
            if(m>=1)
                ans=min(ans, 1+mindist(A, B, n, m-1, dist));
            if(n>=1)
                ans=min(ans, 1+mindist(A, B, n-1, m, dist));
            if(n>=1 && m>=1)
                ans=min(ans, 1+mindist(A, B, n-1, m-1, dist));
        }
        return dist[n][m]=ans;
    }   
}

int Solution::minDistance(string A, string B) {
    int n=A.length();
    int m=B.length();
    vector<vector<int> > dist(n+1, vector<int>(m+1, -1));
    dist[0][0]=0;
    return mindist(A, B, n, m, dist);
}
