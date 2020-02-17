int Solution::maximumGap(const vector<int> &A) {
    if(A.size()==0)
        return -1;
    else if(A.size()==1)
        return 0;
    vector<pair<int, int> > C;
    int len=A.size();
    for(int i=0; i<len; i++){
        C.push_back(make_pair(A[i], i));
    }
    sort(C.begin(), C.end());
    int maxin=C[len-1].second;
    int ans=0;
    for(int i=len-2; i>=0; i--){
        ans = max(ans, maxin-C[i].second);
        maxin = max(maxin, C[i].second);
    }
    return ans;
}
