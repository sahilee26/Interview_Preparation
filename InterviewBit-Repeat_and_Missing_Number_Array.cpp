vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int len=A.size();
    bool arr[len];
    int A1, B1;
    for(int i=0; i<len; i++){
        arr[i]=false;
    }
    // memset(arr, sizeof(arr), false);
    for(int i=0; i<len; i++){
        if(arr[A[i]-1]==false)
            arr[A[i]-1]=true;
        else
            A1=A[i];
    }
    for(int i=0; i<len; i++){
        // cout<<arr[i];
        if(arr[i]==false)
            B1=i+1;    
    }
    vector<int>v;
    v.push_back(A1);
    v.push_back(B1);
    return v;
}
