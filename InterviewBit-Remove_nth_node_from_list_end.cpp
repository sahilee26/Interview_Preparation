/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 

ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    int len=0;

    ListNode* temp=A;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    
    int h=0, pos=max(1, len-B);
    if(pos==1 || pos==0){
        A=A->next;
        return A;
    }
    ListNode* temp1=A;
    
    while(temp1!=NULL){
        if(h==pos-1){
            temp1->next=temp1->next->next;
            break;
        }
        temp1=temp1->next;
    }
    
    return A;
}
