/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::t2Sum(TreeNode* A, int x) {
   if(A==NULL)
        return 0;
    TreeNode* n1=A;
    TreeNode* n2=A;
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    
    while((!s1.empty()|| n1!=NULL) && (!s2.empty()||n2!=NULL)){
        while(n1){
            s1.push(n1);
            n1=n1->left;
        }
        while(n2){
            s2.push(n2);
            n2=n2->right;
        }
        n1=s1.top();
        n2=s2.top();
        if(n1->val+n2->val==x && n1!=n2)
            return 1;
        else if(n1->val+n2->val>x){
            s2.pop();
            n2=n2->left;
            n1=NULL;
        }
        else{
            s1.pop();
            n1=n1->right;
            n2=NULL;
        }
    }
    return 0;
}
