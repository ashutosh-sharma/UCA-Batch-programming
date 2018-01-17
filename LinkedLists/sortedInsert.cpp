/*1*/
/*
structure of the node of the list is as
struct node
{
	int data;
	struct node* next;
};
*/

void sortedInsert(struct node** head, int data){
    node* newNode = new node;
    newNode -> data = data;
    newNode -> next = NULL;
    
    if((*head) == NULL){
        *head = newNode;
        return;
    }
    
    if((*head) -> next == NULL){
        if( (*head) -> data < data){
            (*head) -> next = newNode;
        }
        else{
            newNode -> next = *head;
            *head = newNode;
        }
    }
    else{
        node* temp = new node;
        temp = *head;
        
        if(temp -> data > data){
            newNode -> next = *head;
            *head = newNode;
            return;
        }
        
        while(temp -> next -> data < data){
            if(temp -> next && temp -> next -> next)
                temp = temp -> next;
            else{
                temp -> next -> next = newNode;
                return;
            }
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
}
