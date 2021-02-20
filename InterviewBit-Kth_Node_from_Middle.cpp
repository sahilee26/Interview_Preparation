/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B) {
    
    ListNode* temp=A;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    
    int mid=len/2+1;
    int find1=mid-B;
    int pos=0;
    temp=A;
    
    
    while(temp!=NULL){
        pos++;
        if(pos==find1)
            return temp->val;
        temp=temp->next;
    }
}
