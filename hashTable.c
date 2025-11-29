#include<stdio.h>
int main(){
    int hashTable[10];
    int n,num,i,index;
    for(i=0;i<10;i++){
        hashTable[i]=-1;
    }
    printf("Enter the no. of elements to enter:");
    scanf("%d",&n);
    printf("Enter the elements:");
    for(i=0;i<n;i++){
        scanf("%d",&num);
        index=num%10;
        while(hashTable[index]!=-1){
            index=(num+1)%10;
        }
        hashTable[index]=num;
}
printf("Hash table\n");
for(i=0;i<10;i++){
    printf("Index %d -> %d\n",i,hashTable[i]);
}
return 0;
}
