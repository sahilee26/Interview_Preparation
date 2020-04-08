string Solution::convertToTitle(int A) {    
    string s="";
    while(A){
        int rem=(A%26);
        if(rem){
            char c=rem-1+'A';
            string ans;
            ans.push_back(c);
            s.insert(0, ans);
            A=A/26;
        }
        else{
            s.insert(0,"Z");
            A=((A/26)-1);
        }
    }
    return s;
}
