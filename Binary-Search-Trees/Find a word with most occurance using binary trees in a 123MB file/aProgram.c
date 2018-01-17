#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

struct node{
    char data[100];
    struct node* left;
    struct node* right;
    int f;
};

typedef struct node node;

node* newEle(char* data){                                             //to create a new node
    node* n = (node*) malloc (sizeof(node));
    strcpy(n -> data , data);
    n -> left = n-> right = NULL;
    n -> f = 1;
    return n;
}

/*********GLOBAL DECLARATIONS************/
node* root = NULL;                                                    //declaring a root
int maxF = 0;
node *maxOccur;
/****************************************/

node* insert(node* x, char* data){                                 //to insert a node in a binary search tree
   if(x == NULL){
        node* n = newEle(data);
        x = n;
        return x;
   }
   else{

    if(strcmp(data , x-> data) < 0)
            x-> left = insert (x-> left, data);

        else if(strcmp(data , x-> data) > 0)
            x-> right = insert (x-> right, data);
   }

   return x;
}

node* search(node *x,char *data){
    if(x== NULL || (strcmp(x-> data, data) == 0))
        return x;
    else{
        if(strcmp(x-> data, data) > 0)
            return search(x-> left, data);

        else if(strcmp(x-> data, data) < 0)
            return search(x-> right, data);
    }
}

node* searchOrInsert(char * data){
        node *temp;

        temp = search(root, data);

        if(temp){
            temp -> f = (temp -> f + 1);

            if(maxF < (temp -> f)){
                maxF = temp -> f;
                maxOccur = temp;
                }
       }
        else{
            root = insert(root, data);
        }
}

int main(){
    FILE *fp = fopen("SampleFile.txt","r");

    char *temp = (char*) malloc(25);

    struct timeval begin, end;

    gettimeofday(&begin, NULL);

    while(fscanf(fp, "%s", temp)){

        if(strlen(temp) >= 10)                                  // checking if length is greater than 10
            searchOrInsert(temp);
    }

    gettimeofday(&end, NULL);

    printf("\nWord with most occcurances : %s \nOccurances : %d \n", maxOccur -> data, maxOccur -> f);

    double time = (end.tv_sec - begin.tv_sec) + (end.tv_usec - begin.tv_usec) / 100000.0;
   
    printf("\nTime : %f",time);

    fclose(fp);

    return 0;
}
