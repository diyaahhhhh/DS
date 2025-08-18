#include <stdio.h>
int FRONT=-1,REAR=-1;
void enqueue(int Q[],int SIZE,int ITEM){
    if((REAR+1)%SIZE==FRONT){
        printf("Queue is full!\n");
             }
    else if(REAR==-1){
        FRONT=REAR=0;
        Q[REAR]=ITEM;
        }
    else{
        REAR=(REAR+1)%SIZE;  
        Q[REAR]=ITEM;
        printf("Item added.\n");
        }
            }
void dequeue(int Q[], int SIZE){
    if(FRONT==-1){
        printf("Queue is empty!\n");
        }
    else if(FRONT==REAR){
         printf("Item deleted:%d\n",Q[FRONT]);
         FRONT=REAR=-1;
         }
    else{
    printf("Item deleted:%d\n",Q[FRONT]);
    FRONT=(FRONT+1)%SIZE;
        }
      }
int main(){
   int SIZE, ITEM, ch,i;
   printf("Enter array size:");
   scanf("%d",&SIZE);
   int Q[SIZE];
while(1){
   printf("MENU\n 1. Enqueue\n 2. Dequeue\n 3. Display\n 4. Exit\n");
   printf("Enter choice:");
   scanf("%d",&ch);
   if(ch==1){
      printf("Enter item:");
      scanf("%d",&ITEM);
      enqueue(Q,SIZE,ITEM);
      }
   else if(ch==2){
      dequeue(Q,SIZE);
      }
   else if(ch==3){
    if(FRONT==-1){
       printf("Queue is empty!\n");
        }
    else{
        printf("Elements:\n");
        i=FRONT;
      while(1){
         printf("%d\t",Q[i]);
         if(i==REAR){
            break;
            }
         i=(i+1)%SIZE;
         }
         printf("\n");
            }
               }
   else if(ch==4){
       printf("Exiting...\n"); 
       break;
       }
  }
return 0;
}
