int Solution::solve(const vector<int> &A) {
    vector<int> A1=A;
    sort(A1.begin(), A1.end());
    int len=A.size();
    if(len<=2)
        return len;
    int llap=2;
    int dp[len][len];
    for(int i=0; i<len-1; i++){
        dp[i][len-1]=2;
    }
    for (int j=len-2; j>=1; j--){
        int i=j-1, k=j+1;
        while(i>=0 && k<=len-1){
            if(A1[i]+A1[k]>2*A1[j]){
                dp[i][j]=2;
                i--;
            }
            else if(A1[i]+A1[k]<2*A1[j]){
                k++;    
            }
            else{
                dp[i][j]=dp[j][k]+1; 
                llap=max(llap, dp[i][j]);
                i--;
                k++;
            }
        }
        while(i>=0){
            dp[i][j]=2;
            i--;
        }
    }
    return llap;
}
