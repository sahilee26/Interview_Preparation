int numofpat(int A, int B, vector<int> &C, long long int X){
    int n=C.size();
    long long int total=0;
    int pat=1;
    for(int i=0; i<n; i++){
        total+=C[i];
        if(total>X){
            pat++;
            total=C[i];
        }
    }
    return pat;
}

int Solution::paint(int A, int B, vector<int> &C) {
    int n=C.size();
    long long int sum=0;
    int max1=0;
    for(int i=0; i<n; i++){
        sum = sum%10000003+C[i]%10000003;
        max1=max(max1, C[i]);
        }
    long long int low=max1*B, high=sum*B;
    high=high%10000003;
    while(low<high){
        // cout<<low<<" "<<high<<endl;
        long long int mid=low+(high-low)/2;
        int patt=numofpat(A, B , C, mid/B);
        if(patt<=A){
            high=mid;
        }
        else 
            low=mid+1;
    }
    return low%10000003;
}
