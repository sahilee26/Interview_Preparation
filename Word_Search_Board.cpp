vector<string> m;
string v;

bool ans=false;
int m1, n1;
int xg[]={1,-1, 0, 0};
int yg[]={0, 0, -1, 1};

bool isValid(int m1, int n1, int m ,int n){
    if(m1>=0 && m1<m && n1>=0 && n1<n)
        return true;
    else
        return false;
}

void wordmatch(int j, int x, int y){
    if(ans==true)
        return;
    else if(j==v.size()){
        ans=true;
        return;
    }
    for(int i=0; i<4; i++){
        if(isValid(x+xg[i], y+yg[i], m1, n1) && m[x+xg[i]][y+yg[i]]==v[j])
            wordmatch(j+1, x+xg[i], y+yg[i]);
    }
}

int Solution::exist(vector<string> &A, string B) {
    ans=false;
    m1=A.size();
    n1=A[0].size();
    
    v=B;
    m=A;
    for(int i=0; i<m1; i++){
        for(int j=0; j<n1; j++){
            if(B[0]==A[i][j])
                wordmatch(1, i, j);
        }
    }
    if(ans) 
        return 1;
    else
        return 0;
}
