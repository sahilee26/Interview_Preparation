int Solution::uniquePaths(int A, int B) {
    long long  int ans=1;
    for(int i=B; i<A+B-1; i++){
        ans*=i;
        ans/=(i-B+1);
    }
    return ans;
}

