int Solution::maxSubArray(const vector<int> &A) {
    int len=A.size();
    if(len==0)
        return 0;
    int max_sum=INT_MIN;
    int max_end=0;
    for(int i=0; i<len; i++){
        max_end=max_end+A[i];
        if(max_end>max_sum)
            max_sum=max_end;
        if(max_end<0)
            max_end=0;
    }
    return max_sum;
}
