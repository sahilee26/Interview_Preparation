string Solution::solve(string A) {
    int freq[26];
    memset(freq, 0, sizeof(freq));
    
    queue<char> q;
    // queue stores only the characters that do not repeat in order they appear in string
    string ans;
    
    for(int i=0; i<A.length(); i++){
        freq[A[i]-'a']++;
        if(freq[A[i]-'a']==1)
            q.push(A[i]);
        while(!q.empty() && freq[q.front()-'a']!=1)
            q.pop();
        if(q.empty())
            ans+='#';
        else
            ans+=q.front();
    }
    return ans;
}
