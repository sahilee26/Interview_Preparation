int Solution::singleNumber(const vector<int> &A) {
    int ans=0;
    for(long int  bitp=0; bitp<32; bitp++){
        int count1=0;
        for(int i=0; i<A.size(); i++){
            if((1<<bitp)&A[i])
                count1++;
        }
        if(count1%3==1)
            ans+=pow(2, bitp);
    }
    return ans;
}
