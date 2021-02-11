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
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {
        int rheight=0, lheight=0;
        if(root->left!=NULL){
            lheight = height(root->left);
        }
        if(root->right!=NULL){
            rheight = height(root->right);
        }
        if(lheight==0 && rheight==0 && ((root->left==NULL) && (root->right==NULL)))
            return 0;
        else
            return max(lheight, rheight)+1;
    }

}; //End of Solution
