string Solution::longestPalindrome(string A) {
    int m= A.length();
    int lps[m][m]={0};
    // lps[i][j]==1 if A[i..j] is palindrome
    for(int i=0; i<m; i++){
        lps[i][i]=1;
    }
    int flag=0;
    int ans=1;
    string g;
    for(int i=0; i<m-1; i++){
        if(A[i]==A[i+1]){
            lps[i][i+1]=1;
            if(ans<2){
                ans=2;
                flag=1;
                g=A.substr(i, i+1);
            }
        }
    }
    for(int i=3; i<=m; i++){
        for(int j=0; j+i-1<m; j++){
            if(A[j]==A[j+i-1] && lps[j+1][j+i-2]==1){
                lps[j][j+i-1]=1;
                if(i>ans){
                    ans=i;
                    flag=1;
                    g=A.substr(j, j+i-1);
                }
            }
        }
    }
    char x=A[0];
    if(flag!=1){
        g.push_back(x);
    }
    return g;
}
