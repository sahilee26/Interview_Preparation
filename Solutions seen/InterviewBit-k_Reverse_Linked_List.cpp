/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 
ListNode* Solution::reverseList(ListNode* A, int B) {
    ListNode* curr=A;
    ListNode* prev=NULL;
    ListNode* next=NULL;
    int cnt=0;
    
    while(curr!=NULL && cnt<B){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        cnt++;
    }
    if(next!=NULL)
        A->next=reverseList(next,  B);
    
    return prev;
}

