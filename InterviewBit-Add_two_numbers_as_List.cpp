/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* newNode(int n){
    ListNode* new1=new ListNode(n);
    return new1;
}

ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    
    ListNode *res=NULL, *prev=NULL, *temp=NULL;
    int carry=0;
    while(1){
        if(A==NULL && B==NULL)
            break;
            
        int sum=carry;
        if(A!=NULL)
            sum+=A->val;
        if(B!=NULL)
            sum+=B->val;
            
        temp = newNode(sum%10);
        if(res == NULL)
            res = temp;
        else
            prev->next = temp;
        
        prev=temp;
        
        carry = sum/10;
        if(A!=NULL)
            A=A->next;
        if(B!=NULL)
            B=B->next;
    }
    if(carry>0)
        temp->next=newNode(carry);
    return res;
}
