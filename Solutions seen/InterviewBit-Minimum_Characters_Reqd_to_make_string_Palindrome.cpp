int Solution::solve(string A) {
    string B=A;
    reverse(A.begin(), A.end());
    string C=B+'$'+A;
    
    //Constructing LPS array 
    int m=C.length();
    int j=0, i=1;
    int lps[m];
    lps[0]=0;
    while(i<m){
        if(C[i]==C[j]){
            j++;
            lps[i]=j;
            i++;
        }
        else{
            if(j!=0)
                j=lps[j-1];
            else{ 
                lps[i]=0;
                i++;
            }    
        }
    }
    return A.length()-lps[m-1];
}
