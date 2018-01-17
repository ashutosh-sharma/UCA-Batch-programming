#include<stdio.h>
#include<stdlib.h>

struct TNode{
  int data;
  struct TNode *left, *right;
};
typedef struct TNode TNode;

TNode *newNode(int d){
  TNode* n = (TNode*) malloc(sizeof(TNode));
  n->data = d;
  n->left = NULL;
  n->right = NULL;
  return n;
}

TNode* TreeInsert(TNode *root, int d){
  
  if(root == NULL)
    return newNode(d);
  
  if(root->data < d)
    root->right = TreeInsert(root->right, d);
  
  if(root->data > d)
    root->left = TreeInsert(root->left, d);
  
  return root;
}

void InOrder(TNode *root){
  if(root == NULL)
    return;
  
  InOrder(root->left);
  printf("%d ",root->data);
  InOrder(root->right);
}

struct stack{
    TNode *ar[100];
    int top;
};
typedef struct stack stack;

void push(stack *s, TNode* d){
    s->ar[++s->top] = d;
}

TNode* pop(stack *s){
    return s->ar[s->top--];
}

int isEmpty(stack *s){
    if(s->top == -1)
        return 1;
    return 0;
}

int toggleLevel(int l){
    if(l == 0)
        return 1;
    return 0;
}

int calc(TNode *root){
    stack *s;
    s = (stack *) malloc(sizeof(stack));
    s->top = -1;
    
    int oSum = 0;
    int eSum = 0;
    
    oSum += root->data;
    push(s, root);
    int level = 1;
    int it = 0;
    
    while(!isEmpty(s)){
        stack *s2;
        s2 = (stack*) malloc(sizeof(stack));
        s2->top = -1;
        
        while(!isEmpty(s)){
            TNode* temp = temp = pop(s);
            
            if(temp->left != NULL)
                push(s2, temp->left);

            if(temp->right != NULL)
                push(s2, temp->right);
                
            if(level == 0){
                if(temp->left != NULL)
                    oSum += temp->left->data;
                if(temp->right != NULL)
                    oSum += temp->right->data;
            }
            else{
                if(temp->left)
                    eSum += temp->left->data;
                if(temp->right)
                    eSum += temp->right->data;
            }
        }
        
        s = s2;
        
        level = toggleLevel(level);
    }
    
    return oSum - eSum;
}


int main(){
  TNode *root = NULL;
  root = TreeInsert(root,5);
  root = TreeInsert(root,3);
  root = TreeInsert(root,7);
  root = TreeInsert(root,1);
  root = TreeInsert(root,6);
  
  printf("\nDifference: %d", calc(root));
  
  return 0;
}
