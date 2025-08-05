#include <stdio.h>
int FRONT=-1,REAR=-1;

//Enqueue
void enqueue(int Q[],int n, int ITEM){
    printf("---ENQUEUE---\n");
    if(REAR==n-1){
        printf("Overflow. Exiting...\n");
        return;
    }
    if(FRONT==-1){
        FRONT=0;
        }
    REAR++;
    Q[REAR]=ITEM;
    printf("Enqueued!\n");
    }

//Dequeue
void dequeue(int Q[], int n){
    int ITEM;
    printf("---DEQUEUE---\n");
    if(REAR<FRONT || FRONT==-1){
        printf("Underflow. Exiting...\n");
        return;
    } 
    ITEM=Q[FRONT];      
    printf("Item dequeued.\n");
    FRONT++;
    if(FRONT>REAR){
         FRONT=REAR=-1;
      }
  }
int main(){
    int n,ch,ITEM;
    printf("Enter queue size:");
    scanf("%d",&n);
    int Q[n];
    FRONT=REAR=-1;
    while(1){
    printf("MENU\n");
    printf("1. Enqueue\n2. Dequeue\n3. Exit\n");
        printf("Enter choice:");
        scanf("%d",&ch);
        if(ch==3){
            printf("Exiting...\n");
        }
        else if(ch==1){
           printf("Enter item to be enqueued:");
           scanf("%d",&ITEM);
           enqueue(Q,n,ITEM);
                }
        else if (ch==2){
             dequeue(Q,n);
             }
         }
return 0;
}
