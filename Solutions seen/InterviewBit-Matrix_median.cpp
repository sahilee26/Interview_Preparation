int Solution::findMedian(vector<vector<int> > &A) {
    int m=A.size();
    if(m==0)
        return 0;
    int n=A[0].size();
    int mat[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            mat[i][j]=A[i][j];
        }
    }
    int min_elem=mat[0][0], max_elem=mat[0][n-1]; 
    for(int i=1; i<m; i++){
        min_elem=min(min_elem, mat[i][0]);
    }
    for(int i=1; i<m; i++){
        max_elem=max(max_elem, mat[i][n-1]);
    }
    int mid=(max_elem+min_elem)/2;
    int x=0;
    while(max_elem > min_elem){
        x=0;
        mid=(max_elem + min_elem)/2;
        for(int i=0; i<m; i++){
            x+=(upper_bound(mat[i], mat[i]+n, mid)-mat[i]);
        }
        int elem=(m*n+1)/2;
        if(x < elem){
            min_elem = mid+1;
        }
        else
            max_elem = mid;
    }
    return min_elem;
}
