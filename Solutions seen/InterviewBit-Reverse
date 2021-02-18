/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* reverse(ListNode* head){

    ListNode *prev=NULL, *next=NULL;
    ListNode* curr=head;
    
    while(curr){
        next=curr->next;
        curr->next=prev;
        curr=next;
        prev=curr;
    }
    
    return prev;
}
 
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(B==C)
        return A;
        
    ListNode *temp=NULL, *temp_prev=NULL;
    ListNode *tempend=NULL, *tempend_next=NULL;
    
    int i=1;
    ListNode* curr=A;
    while(curr && i<=C){
        if(i<B){
            temp_prev=curr;
        }
        
        if(i==B){
            temp=curr;
        }
        
        if(i==C){
            tempend=curr;
            tempend_next=curr->next;
        }
        curr=curr->next;
        i++;
    }
    tempend->next=NULL;
    
    tempend=reverse(temp);
    
    if(temp_prev!=NULL)
        temp_prev->next=tempend;
    else
        A=tempend;
        
    temp->next=tempend_next;
    
    return A;
}
