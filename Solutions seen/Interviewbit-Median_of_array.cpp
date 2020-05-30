#define INF 1000000000

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int m=A.size();
    int n=B.size();
    
    // Base cases
    if(m==0){
        return ((double)B[(n-1)/2]+(double)B[n/2])/2.0;
    }
    else if(n==0)
        return ((double)A[(m-1)/2]+ (double)A[m/2])/2.0;
    
    
    // min(log(m), log(n)) approach
    if(m>n){
        return findMedianSortedArrays(B, A);
    }
    int start=0;
    int end=m;
    int px, py;
    // px in no of elements in left partition x
    while(start<end){
        px=(start+(end-start)/2);
        py=(m+n+1)/2-px;
        int leftx, rightx, lefty, righty;
        if(px==0)
            leftx=-INF;
        else 
            leftx=A[px-1];
        if(px==m)
            rightx=INF;
        else
            rightx=A[px];
        if(py==0)
            lefty=-INF;
        else
            lefty=B[py-1];
        if(py==n)
            righty=INF;
        else    
            righty=B[py];
            
        if(leftx<=righty && rightx>=lefty){
            if((m+n)%2==1)
                return max(leftx,lefty);
            else
                return ((double)max(leftx,lefty)+ (double)min(righty,rightx))/2.0;
        }
        else if(leftx>righty){
            end=px;
        }
        else{
            start=px+1;
        }
        
    }
}
