int dp[501][501][2];

int rec(vector<int> A, int st, int end, int state){
    if(dp[st][end][state]!=-1)
        return dp[st][end][state];
    if(st==end){
        if(state==0)
            return dp[st][end][state]=A[st];
        else
            return 0;
    }
    if(state==0)
        return dp[st][end][state]=max(A[st]+ rec(A, st+1, end, 1), A[end] + rec(A, st, end-1, 1));
    else
        return dp[st][end][state]=min( rec(A, st+1, end, 0),  rec(A, st, end-1, 0));
}

int Solution::maxcoin(vector<int> &A) {
    int len=A.size();
    
    for(int i=0; i<=len; i++){
        for(int j=0; j<=len; j++){
            dp[i][j][0]=-1;
            dp[i][j][1]=-1;
        }
    }
    return rec(A, 0, len-1, 0);
}

