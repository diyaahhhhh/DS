#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int TOP=-1;
char stack[10];

void push(char c){
    TOP+=1;
    stack[TOP]=c;
}
char pop(){
    char c;
    c=stack[TOP];
    TOP-=1;
    return c;
}
int precedenceOp(char c){
    if(c=='*' || c=='/'){
        return 1;
    }
    else if(c=='+' || c=='-'){
        return 2;
    }
}
void postfix(char infix[]){
    char postfixExp[10];
    char c;
    int i=0,j=0;
    for(i;i<strlen(infix);i++){
        c=infix[i];
        if(isalnum(c)){
            postfixExp[j]=c;
            j+=1;
        }
        else if(c=='('){
          push(c);
        }
       else if(c==')'){
           while (stack[TOP] != '(') {
               postfixExp[j++] = pop();
                      }
            pop(); 
       }
       else{
           while(TOP!=-1 && stack[TOP]!='(' && precedenceOp(stack[TOP])<=precedenceOp(c)){
               postfixExp[j]=pop();
               j+=1;
           }
           push(c);
       }
    }
     while(TOP!=-1){
         postfixExp[j]=pop();
         j+=1;
     }
    postfixExp[j] = '\0';
    printf("Postfix:%s\n",postfixExp);
}
int main(){
    char infix[10];
    printf("Enter an infix expression:");
    scanf("%s",&infix);
    postfix(infix);
    return 0;
}
