string Solution::countAndSay(int A) {
    if(A==0)
        return "";
    else if(A==1)
        return "1";
    string prev="1";
    string curr=prev;
    for(int i=2; i<=A; i++){
        curr.clear();
        for(int j=0; j<prev.length(); j++){
            int count=1;
            while(j+1<prev.length() && prev[j]==prev[j+1]){
                count++;
                j++;
            }
            curr.append(to_string(count) + prev[j]);
        }
        prev=curr;
    }
    return curr;
}
