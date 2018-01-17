/* A program to find lowest common ancestor of two nodes in a BST */
#include<stdio.h>
#include<stdlib.h>

struct TNode{
    int data;
    struct TNode* left, * right;
};

typedef struct TNode TNode;

TNode* newNode(int d){
    TNode* n = (TNode*) malloc(sizeof(TNode));
    n -> data = d;
    n->left = n->right = NULL;
    return n;
}

TNode* insert(TNode* root, int d){
    if(root == NULL){
        return newNode(d);
    }
    
    if(root->data > d){
        root->left = insert(root->left, d); 
    }
    else    
    if(root -> data < d){
        root->right = insert(root->right, d); 
    }
    
    return root;
}

int lca(TNode* root, int a, int b){
    int res;
    
    if(root == NULL){
        return -1;
    }
    
    // when we have to find ancestor of a arm
    if(root->data == a || root->data == b){
        return root->data;
    }
    
    // drifting to right when root is smaller than both a and b
    if(root -> data < a && root-> data < b){
        res = lca(root -> right, a, b);
    }
    
    //drifting towards left when root is larger than both a and b    
    if(root -> data > a && root-> data > b){
        res = lca(root -> left, a, b);
    }
    
    if(root -> data > a && root -> data < b){
         return root-> data;
    }
    return res;
}

int main(){
    TNode* root = NULL;
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 3);
    root = insert(root, 9);
   
    /* Tree:
            5
          /   \
         2     7
       /  \  /  \
      1   3  6   9
    */
    
    /************
    e.g.
    lca(1,3) = 2
    lca(2,9) = 5
    lca(1,2) = 2
    *************/
    
    // 'a' and 'b' nodes
    // 'a' must be smaller than 'b'
    
    int a = 1, b = 2;
    
    printf("%d", lca(root, a, b));
    return 0;
}

/******
OUTPUT:
    2
    *********/
