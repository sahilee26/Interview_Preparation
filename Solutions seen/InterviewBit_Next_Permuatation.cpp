vector<int> Solution::nextPermutation(vector<int> &A) {
    int len=A.size();
    int i=len-1;
    for( ; i>0; i--){
        if(A[i]>A[i-1]){
            break;
        }
    }
    if(i==0){
        sort(A.begin(),A.end());
        return A;
    }
    int ind=i;
    for(int j=i+1; j<len; j++){
        if(A[j]<A[ind] && A[i-1]<A[j]){
            ind=j;
        }
    }
    int temp=A[ind];
    A[ind]=A[i-1];
    A[i-1]=temp;
    sort(A.begin()+i, A.end());
    return A;
}
