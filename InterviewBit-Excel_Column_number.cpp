int Solution::titleToNumber(string A) {
    int len=A.size();
    int ans=0;
    int pow1=0;
    for(int i=len-1; i>=0; i--){
        ans+=(pow(26,pow1)*(A[i]-'A'+1));
        pow1++;
    }
    return ans;
}
