int LCS[101][101];
int findlcs(string s1, string s2, int len1, int len2){
    if(LCS[len1][len2]!=INT_MIN)
        return LCS[len1][len2];
    int ans= max(findlcs(s1, s2, len1-1, len2), findlcs(s1, s2, len1, len2-1));
    if(len1!=len2 && s1[len1-1]==s2[len2-1])
        ans=max(ans, findlcs(s1, s2, len1-1, len2-1)+1);
    return ans;
}


int Solution::anytwo(string A) {
    string B=A;
    int len=A.length();
    for(int i=0; i<=len; i++){
        for(int j=0; j<=len; j++){
            LCS[i][j]=INT_MIN;
        }
    }
    for(int i=0; i<=len; i++){
        LCS[i][0]=0;
        LCS[0][i]=0;
    }
    if(findlcs(A, B, len, len)>=2)
        return 1;
    else 
        return 0;
}
