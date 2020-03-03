int Solution::jump(vector<int> &A) {
    int len=A.size();
    int maxReach=A[0];
    int currmaxReach=A[0];
    int jumps=1;
    if(len<=1)
        return 0;
    for(int i=1; i<=maxReach; i++){
        if(i==len-1)
            return jumps;
        currmaxReach=max(currmaxReach, A[i]+i);
        if(i==maxReach){
            if(i==currmaxReach)
                return -1;
            jumps++;
            maxReach=currmaxReach;
        }
    }
    return -1;
}
