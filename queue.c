#include <stdio.h>
int FRONT=-1,REAR=-1;

//Enqueue
void enqueue(int Q[],int n){
    int ITEM,i;
    printf("---ENQUEUE---\n");
    if(REAR==n-1){
        printf("Overflow. Exiting...\n");
        return;
    }
    if(REAR==-1){
        FRONT=REAR=0;
        printf("Enter items to be added:");
        for(i=0;i<n;i++){
            scanf("%d",&ITEM);
            Q[REAR]=ITEM;
            REAR++;
        }
    }
    printf("Success!\n");
    }

//Dequeue
void dequeue(int Q[], int n){
    int ITEM,i;
    printf("---DEQUEUE---\n");
    if(REAR<FRONT || FRONT==-1){
        printf("Underflow. Exiting...\n");
        return;
    }
    else{
        FRONT=0;
        ITEM=Q[FRONT];
        FRONT++;
        }
    printf("Items deleted.");
    }

int main(){
    int n,ch,A[3];
    printf("MENU\n");
    printf("1. Enqueue\n2. Dequeue\n3. Exit\n");
        printf("Enter choice:");
        scanf("%d",&ch);
        if(ch==3){
            printf("Exiting...");
        }
        else if(ch==1){
           printf("Enter array size:");
           scanf("%d",&n);
           int A[n];
           enqueue(A,n);
                }
        else if (ch==2){
             dequeue(A,n);
         }
return 0;
}
