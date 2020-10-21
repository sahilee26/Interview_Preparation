/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
void push_node(ListNode** nodefin, ListNode** nodeini){
    
    ListNode* newNode=*nodeini;
    
    *nodeini=newNode->next;
    newNode->next=*nodefin;
    *nodefin=newNode;
}

ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    struct ListNode trash=ListNode(1);
    ListNode* newList=&trash;
    trash.next=NULL;
    while(1){
        if(A==NULL){
            newList->next=B;
            break;
        }
        else if(B==NULL){
            newList->next=A;
            break;
        }
        else if(A->val<=B->val){
            push_node(&(newList->next), &A);
        }
        else{
            push_node(&(newList->next), &B);
        }
        newList=newList->next;
    }
    return trash.next;
}
