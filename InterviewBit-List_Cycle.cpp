/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
   ListNode* temp=A;
   map<int, int> mp;
   while(temp!=NULL){
        if(mp[temp->val]!=1)
            mp[temp->val]=1;
        else
            return temp;
        temp=temp->next;
   }
    return NULL;
}
