int Solution::solve(string A) {
    int n=A.size();
    int count1=0;
    int i=0, j=n-1;
    int flag1=0, flag2=0;
    while(i<j){
        if(A[i]==A[j]){
            i++;
            j--;
        }
        else{
            int k=i+1;
            int l=j-1;
            while(k<j){
                if(A[k]!=A[j]){
                    flag1=1;
                    break;
                }
                else{
                    k++;
                    j--;
                }
                    
            }
            while(i<l){
                if(A[i]!=A[l]){
                    flag2=1;
                    break;
                }
                else{
                    i++;
                    l--;
                }
            }
            break;
        }
    }
    if(flag1==1 && flag2==1)
        return 0;
    else
        return 1;
}
