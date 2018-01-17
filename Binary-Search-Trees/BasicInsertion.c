#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

typedef struct node node;

node* newEle(int data){                                             //to create a new node
    node* n = (node*) malloc (sizeof(node));
    n -> data = data;
    n -> left = n-> right = NULL;
    return n;
}

node* root = NULL;

node* insert(node* root, int data){                                 //to insert a node in a binary search tree
   if(root == NULL){
        node* n = newEle(data);
        root = n;
        return root;
   }
   else{
        
        if(data <= root -> data)
            root -> left = insert (root -> left, data);
        else
            root -> right = insert (root -> right, data);
   }

   return root;
}

int minimumElement(node *root){                                               //to find the minimum element in a tree
    if(root == NULL)
        return -1;                          //when root is NULL[Empty Tree]
    
    while(root -> left != NULL){
        root = root -> left;
    }

    return root -> data;
}

int maximumElement(node* root){
    if(root == NULL)
        return -1;

    while(root -> right != NULL){
        root = root -> right;
    }

    return root -> data;

}

int height(node* root){
    
}
void print(node* root){
    printf("%d", root -> data);
}

int main(){
    
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 21);
    root = insert(root, 4);
    printf("\nRoot :");
    print(root);
    printf("\nMinimum Element : %d",minimumElement(root));
    printf("\nMaximum Element : %d",maximumElement(root));
    printf("\n");
    return 0;
}
