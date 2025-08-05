#include<stdio.h>
int FRONT=-1,REAR=-1;
void enqueue(int Q[], int SIZE, int ITEM){
    if(REAR==SIZE-1){
        printf("Overflow!");
        return;
    }
    else{
        if(FRONT==-1){
           FRONT=0;
        }
        REAR++;
        Q[REAR]=ITEM;
        printf("Item inserted.\n");
        }
    }
void dequeue(int Q[],int ITEM){
    if(FRONT==-1 || FRONT>REAR){
        printf("Underflow!\n");
    }
    else{
        ITEM=Q[FRONT];
        FRONT++;
        printf("Item deleted.\n");
        if(FRONT>REAR){
            FRONT=REAR=-1;
        }
    }
}
int main(){
    int i,SIZE,ITEM,ch;
    printf("Enter array size:");
    scanf("%d",&SIZE);
    int Q[SIZE];
while(1){
    printf("MENU\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    printf("Enter choice:");
    scanf("%d",&ch);
    if (ch==1){
        printf("Enter item:");
        scanf("%d",&ITEM);
        enqueue(Q,SIZE,ITEM);
    }
    else if (ch==2){
        dequeue(Q,ITEM);
    }
    else if(ch==3){
        if(FRONT==-1 || FRONT>REAR)
        {
            printf("Empty queue!\n");
        }
        else{
          for(i=0;i<SIZE;i++){
            printf("%d\t");}
        }
    }
    else{ 
        if(ch==4){
        printf("Exiting..");}
    break;}    
}
return 0;
}
