/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    ListNode* temp1=A;
    ListNode* temp2=A;
    
    ListNode *curr = A;
    
     //find len of list
    while(curr){
        l++;
        currprev = curr; //points to last element of list after loop ends
        curr = curr->next;
    }
    
    for(int i=0; i<B; i++){
        temp2=temp2->next;
    }
    if(temp2!=NULL){
        while(temp2->next!=NULL){
            temp1=temp1->next;
            temp2=temp2->next;
        }
    
        temp2->next=A;
        A=temp1->next;
        temp1->next=NULL;
    }
    return A;
    
}
