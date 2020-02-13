int Solution::longestSubsequenceLength(const vector<int> &A) {
    int len=A.size();
    if(len<=1)
        return len;
        
    int LIS[len], LDS[len];
    int ans=INT_MIN;
    LIS[0]=1;
    LDS[len-1]=1;
    for(int i=1; i<len; i++){
        LIS[i]=1;
        for(int j=0; j<i; j++){
            if(A[j]<A[i])
                LIS[i]=max(LIS[i], LIS[j]+1);
        }
        // cout<<LIS[i]<<endl;
    }
    for(int i=len-2; i>=0; i--){
        LDS[i]=1;
        for(int j=len-1; j>i; j--){
            if(A[j]<A[i])
                LDS[i]=max(LDS[i], LDS[j]+1);
        }
    }
    for(int i=0; i<len; i++){
        ans=max(ans, LDS[i]+LIS[i]-1);
    }
    return ans;
}
