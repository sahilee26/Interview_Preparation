bool is_match(string A, string B, int n, int m, vector<vector<int> >& rem){
    if(rem[n][m]!=-1)
        return rem[n][m];
    else if(n<1 && m<1)
        return rem[n][m]=1;
    else if(m<1)
        return rem[n][m]=0;
    bool ans=0;
    if(m>0 && (B[m-1]=='.' ||(n>0 && B[m-1]==A[n-1])))
        ans=is_match(A, B, n-1, m-1, rem);
    if(m>0 && B[m-1]=='*'){
        // zero occurences of character before '*' 
        ans=(ans || is_match(A, B, n, m-2, rem));
        
        if(m>1 && (B[m-2]==A[n-1] || B[m-2]=='.')){    
            // one or more occurences of character before '*'
            ans= (ans || is_match(A, B, n-1, m, rem));
        }
    }
    return rem[n][m]=ans;
}


int Solution::isMatch(const string str, const string pat) {
    int n=str.length();
    int m=pat.length();
    vector<vector<int> > rem(n+1, vector<int> (m+1, -1));
    rem[0][0]=1;
    return is_match(str, pat, n, m, rem);
}
