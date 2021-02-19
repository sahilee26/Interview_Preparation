/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    ListNode* temp1 = A;
    ListNode* temp2 = B;
    
    map<ListNode*, int> mp;
    while(temp1!=NULL){
        mp[temp1]=1;
        temp1=temp1->next;
    }
    
    while(temp2!=NULL){
        if(mp[temp2]==1)
            return temp2;
        temp2=temp2->next;
    }
    return NULL;
}
