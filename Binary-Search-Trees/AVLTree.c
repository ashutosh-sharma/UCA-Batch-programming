#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

typedef struct Node Node;

Node* newNode(int d){
    Node *new = (Node*) malloc(sizeof(Node));
    new -> data = d;
    new -> left = NULL;
    new -> right = NULL;

    //as node is initially added as a leaf
    new -> height = 1;
    return new;
}

int height(Node *node){
    if(node == NULL)
        return 0;

    return node->height;

}

int getBalance(Node* node){
    if(node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

int max(int a, int b){
    return a > b ? a : b;
}

Node* leftRotation(Node *node){
    Node *temp = node->right;
    Node *temp2 = temp->left;
     
    // Perform rotation
    temp->left = node;
    node->right = temp2;
        
    //  Update heights
    node->height = max(height(node->left), height(node->right))+1;
    temp->height = max(height(temp->left), height(temp->right))+1;
                               
    // Return new root
    return temp;
}

Node* rightRotation(Node* node){
    Node *temp = node->left;
    Node *temp2 = temp->right;
         
    // Perform rotation
    temp->right = node;
    node->left = temp2;
                      
    // Update heights
    node->height = max(height(node->left), height(node->right))+1;
    temp->height = max(height(temp->left), height(temp->right))+1; 

     return temp;
}

Node* insert(Node* node, int key){
    //Duplicate values not allowed in AVL Balanced tree.
    
    if(node == NULL){
        return (newNode(key));
    }
    
    if(key < node->data){
        node -> left = insert(node -> left, key);
    }else{
        node -> right = insert(node -> right, key);
    }

    //updating height of inserted node
    node -> height = 1 + max(height(node->left), height(node->right));
    
    //calculate balance = height(node -> left) - height(node -> right)
    int bal = getBalance(node);

    //If tree becomes unbalanced then 4 cases
    
    //1.left-left case
    if(bal > 1 && key < node -> left ->data){
        return rightRotation(node);    
    } 

    //2.left-right case
    if(bal > 1 && key > node -> left -> data){
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }

    //3.right-left case
    if(bal < -1 && key < node -> right -> data){
        node -> right = rightRotation(node -> right);
        return leftRotation(node);
    }

    //4.right-right case
    if(bal < -1 && key > node -> right -> data){
        return leftRotation(node);
    }

    return node;
}   

void preOrder(Node *node){
    if(node == NULL) return;

    printf("%d ", node->data);

    preOrder(node->left);
    preOrder(node->right);
}

int main(){
    //declaring root node as NULL
    Node *root = NULL;
    
    root = insert(root, 10);
    root = insert(root, 8);
    root = insert(root, 6);
    root = insert(root, 2);
    root = insert(root, 15);
   
    preOrder(root);
    return 0;   
}
