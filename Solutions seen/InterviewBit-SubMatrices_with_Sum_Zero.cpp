int Solution::solve(vector<vector<int> > &A) {
    int m=A.size(),n;
     if(m!=0)
        n=A[0].size();
    else
        return 0;
    int count=0;
    // i and j will decide size of matix (i+1)*(j+1)
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
           if(i>0)  A[i][j]+=A[i-1][j];
           if(j>0)  A[i][j]+=A[i][j-1];
           if(i>0 && j>0)   A[i][j]-=A[i-1][j-1];
        }
    }
    for(int i=0; i<m ; i++){
        for(int j=0; j<n; j++){
            for(int k=i; k<m; k++){
                for(int l=j; l<n; l++){
                    int new_sum=A[k][l];
                    if(i>0) new_sum-=A[i-1][l];
                    if(j>0) new_sum-=A[k][j-1];
                    if(i>0 && j>0) new_sum+=A[i-1][j-1];
                    if(new_sum==0)
                        count++;
                }
            }
        }
    }
    return count;
}
