ListNode* Solution::solve(ListNode* A) {
    ListNode* temp=A;
    int n1=0, n2=0;
    
    while(temp!=NULL){
        if(temp->val==0)
            n1++;
        else
            n2++;
        temp=temp->next;
    }
    ListNode* temp1=A;
    
    int l=0;
    while(temp1!=NULL){
        if(l<n1){
            temp1->val=0;
            l++;
        }
        else
            temp1->val=1; 
        temp1=temp1->next;
    }
    return A;
}
