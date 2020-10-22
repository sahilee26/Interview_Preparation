int Solution::lengthOfLongestSubstring(string A) {
    int i=0, j=0;
    int freq[128];
    memset(freq, 0, sizeof(freq));
    
    int ans=0;
    
    while(i<A.size() && j<A.size()){
        freq[A[j]-'!']++;
        if(freq[A[j]-'!']>1){
            int k=i;
            for(; k<j; k++){
                if(A[k]!=A[j])
                    freq[A[k]-'!']=0;
                else
                    break;
            }
            i=k+1;
            freq[A[j]-'!']=1;
        }
        if(j-i+1>ans)
            ans=j-i+1;
        j++;
    }
    return ans;
}
