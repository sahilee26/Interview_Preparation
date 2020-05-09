int maxHist(int B[], int n){
    stack<int> result;
    int area=0;
    int top_val;
    int max_area=0;
    int i=0;
    while(i<n){
        if(result.empty() || B[result.top()]<=B[i])
            result.push(i++);
        else{
            top_val=B[result.top()];
            result.pop();
            area=top_val*i;
            if(!result.empty())
                area=top_val*(i-result.top()-1);
            max_area=max(area, max_area);
        }
    }
    while(!result.empty()){
        top_val=B[result.top()];
        result.pop();
        area=top_val*i;
        if(!result.empty())
            area=top_val*(i-result.top()-1);
        max_area=max(area, max_area);
    }
    return max_area;
}


int Solution::maximalRectangle(vector<vector<int> > &A) {
    int m=A.size();
    int n=A[0].size();
    int hist[m][n]={0};
    for(int i=0; i<n; i++){
        hist[0][i]=A[0][i];
    }
    int ans=maxHist(hist[0], n);
    for(int i=1; i<m; i++){
        for(int j=0; j<n; j++){
            if(A[i][j]==1)
                hist[i][j]=hist[i-1][j]+A[i][j];
            else
                hist[i][j]=0;
        }
        ans=max(ans, maxHist(hist[i], n));
    }
    return ans;
}
