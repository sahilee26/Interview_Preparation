int Solution::maximumGap(const vector<int> &A) {
    vector<int> c=A;
    if(c.size()<2)
        return 0;
    sort(c.begin(), c.end());
    int diff=INT_MIN;
    for(int i=0; i<c.size()-1; i++){
        diff=max(diff,c[i+1]-c[i]);
    }
    return diff;
}
