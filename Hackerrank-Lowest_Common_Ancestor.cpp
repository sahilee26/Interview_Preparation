#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
#define pb push_back

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};
   
    
*/  
   
    
    bool find(Node *root, vector<Node*> &dummy, int data1){
        if(root == NULL)
            return false;
            
        dummy.pb(root);
        
        if(root->data==data1)
            return true;
        if((root->left!=NULL && find(root->left, dummy, data1)) || (root->right!=NULL && find(root->right, dummy, data1)))
            return true;
        
        dummy.pop_back();
        return false;
    }
  
    Node *lca(Node *root, int v1, int v2) {
        vector<Node*> path1, path2;
        
        if(!find(root, path1, v1) || !find(root, path2, v2))
            return NULL;
            
        else{   
            int i=0;
            while(i<path1.size() && i<path2.size()){
                if(path1[i]->data==path2[i]->data)
                    i++;
                else
                    break;
            }
            return path1[i-1];
        }
    }
    

}; //End of Solution
