vector<int> Solution::flip(string A) {
    int m=A.length();
    int flips=0, flips_max=-1;
    int l=-1, r=-1, l1=-1, r1=-1;
    for(int i=0; i<m; i++){
        if(A[i]=='0'){
            flips++;
            if(l1==-1){
                l1=i+1;
                r1=i+1;
            }
            else
                r1++;
        }
        else{
            flips--;
            if(flips>=0)
                r1++;   
            else{
                l1=-1;
                r1=-1;
                flips=0;
            }
        }
        if(flips>flips_max || flips_max==-1){
            l=l1;
            r=r1;
            flips_max=max(flips_max, flips);
        }
    }
    vector<int> v;
    if(l!=-1 && r!=-1){
        v.push_back(l);
        v.push_back(r);
    }
    return v;
}
