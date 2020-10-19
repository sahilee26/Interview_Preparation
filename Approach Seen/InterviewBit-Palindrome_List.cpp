/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int lenlin(ListNode* head){
    ListNode* trash=head;
    
    int len=0;
    while(trash){
        trash=trash->next;
        len++;
    }
    return len;
} 

void ReverseLinList(ListNode* head){
    if(head->next==NULL)
            return;
    ListNode* curr=head->next->next;
    ListNode* prev=head->next;
    ListNode* next=NULL;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head->next=prev;
    
}

int Solution::lPalin(ListNode* A) {
    int len=lenlin(A);
    
    ListNode* trash=A;
    int ptr=0;
    while(ptr<len/2-1){
        trash=trash->next;
        ptr++;
    }
    ReverseLinList(trash);
    trash=trash->next;
    
    ptr=0;
    while(ptr<len/2){
        if(A->val!=trash->val)
            return false;
        else
            A=A->next;
            trash=trash->next;
        ptr++;
    }   
    return true;
}
