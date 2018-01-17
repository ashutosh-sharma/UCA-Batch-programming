/*********
PROGRAM TO EVALUATE RESULT OF POSTFIX EXPRESSION USING STACKS in C language. 
(this program will not check if your psot-fix expression is valid or not)
**********/

#include<stdio.h>
#include<string.h>

struct Stack{           //Stack declaration
    char a[1000];
    int top;
};

struct Stack s;         

int pop(){              //pop operation for stack
    return s.a[s.top--];       
}

void push(int x){       //push operation for stack
    s.a[++s.top] = x;
}

int main(){
    s.top = -1;

    char exp[1000];
    printf("\nEnter Post-fix epression to evaluate:[max_size-1000]: ");
    scanf("%s",exp);

    int i;

    for(i = 0; i< strlen(exp); i++){
        
        if(exp[i] == '*' || exp[i] == '+' || exp[i] == '-' || exp[i] == '/'){
         
            int a = pop();
            int b = pop();
            int temp;

            if(exp[i] == '*'){
              temp = b * a;
            }

             if(exp[i] == '+'){
                temp = b + a;
            }
         
            if(exp[i] == '-'){
                temp = b - a;
            }

            if(exp[i] == '/'){
                temp = b / a;
            }

            push(temp);
        }

        else{
            push(exp[i] - '0');
        }
    }

    printf("ANSWER:%d\nProgram successfully terminated!\n\n",s.a[s.top]);
    
    return 0;
}
