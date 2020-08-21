int Solution::solve(string A) {
    int len=A.size();
    int LPS[len+1][len+1];
    for(int i=0; i<=len; i++){
        for(int j=0; j<=len; j++)
            LPS[i][j]=0;
    }
    for(int i=1; i<=len; i++){
        LPS[i][i]=1;
        if(i==len)
            continue;
        if(A[i-1]==A[i])    
            LPS[i][i+1]=2;
        else
            LPS[i][i+1]=1;
    }
    for(int i=2; i<len; i++){
        //i denotes length of substring for ans is being calculated
        for(int j=1; j+i<=len; j++){
            int k=j+i;
            int ans=INT_MIN;
            ans = max(LPS[j+1][k], LPS[j][k-1]);
            if(A[k-1]==A[j-1])
                ans = max(ans, LPS[j+1][k-1]+2);
            LPS[j][k] = ans;
        }
    }
    return LPS[1][len]; 
}
