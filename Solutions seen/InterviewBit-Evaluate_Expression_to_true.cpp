int T[155][155];
int F[155][155];
int total[155][155];


int mod=1003;
int Solution::cnttrue(string A) {
    int len=A.length();
    for(int i=0; i<len; i+=2){
        if(A[i]=='T'){
            T[i][i]=1;
            F[i][i]=0;
        }
        else{
            F[i][i]=1;
            T[i][i]=0;
        }
        total[i][i]=1;
    }
    // return T[len-1][len-1];
    for(int gap=2; gap<len; gap+=2){    
        for(int i=0; i+gap<len; i+=2){
            int j=i+gap;
            T[i][j]=0;
            F[i][j]=0;
            for(int k=i; k<=j; k+=2){
                if(A[k+1]=='&'){
                    T[i][j]+=(T[i][k]*T[k+2][j])%mod;
                    F[i][j]+=(total[i][k]*total[k+2][j])%mod-(T[i][k]*T[k+2][j])%mod;
                }
                else if(A[k+1]=='|'){
                    T[i][j]+=(total[i][k]*total[k+2][j])%mod-(F[i][k]*F[k+2][j])%mod;
                    F[i][j]+=(F[i][k]*F[k+2][j])%mod;
                }
                else if(A[k+1]=='^'){
                    T[i][j]+=(F[i][k]*T[k+2][j])%mod+(T[i][k]*F[k+2][j])%mod;
                    F[i][j]+=(F[i][k]*F[k+2][j])%mod+(T[i][k]*T[k+2][j])%mod;
                }
            }
            total[i][j]=(T[i][j]+F[i][j])%mod;
        }
    }
    return T[0][len-1]%mod;
}
