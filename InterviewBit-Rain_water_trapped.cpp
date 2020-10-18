int Solution::trap(const vector<int> &A) {
    int len=A.size();
    int pre[len];
    int suf[len];
    pre[0]=A[0];
    for(int i=1; i<len; i++){
        pre[i]=max(pre[i-1], A[i]);
    }
    suf[len-1]=A[len-1];
    for(int i=len-2; i>=0; i--){
        suf[i]=max(suf[i+1], A[i]);
    }
    int ans=0;
    for(int i=1; i<len-1; i++){
        if(pre[i]<=A[i] && suf[i]>=A[i]){
            ans+=min(pre[i], suf[i])-A[i];
        }
    }
    return ans;
}
