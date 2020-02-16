int Solution::repeatedNumber(const vector<int> &A) {
    int len=A.size();
    bool arr[len];
    memset(arr, 0, sizeof(arr));
    for(int i=0; i<len; i++){
        if(arr[A[i]-1]==false)
            arr[A[i]-1]=true;
        else
            return A[i];
    }
}
