#include <stdio.h>
struct POL{
    int coeff,expo;
}p1[5],p2[5],sum[5];
int main() {
   int i,j,k,n1,n2,n3;
   printf("Enter no. of terms of 1st polynomial:");
   scanf("%d",&n1);
   printf("Enter coefficient and degree respectively:");
   for(i=0;i<n1;i++){
       scanf("%d%d",&p1[i].coeff,&p1[i].expo);
   }
   printf("Enter no. of terms of 2nd polynomial:");
   scanf("%d",&n2);
   printf("Enter coefficient and degree respectively:");
   for(j=0;j<n2;j++){
       scanf("%d%d",&p2[j].coeff,&p2[j].expo);
   }
   if(n1>n2){
       n3=n1;
           }
   else{
       n3=n2;
       }
   for(i=0,j=0,k=0;i<n1,j<n2,k<n3;i++,j++,k++){
       if (p1[i].expo==p2[j].expo){
           sum[k].coeff=p1[i].coeff+p2[j].coeff;
           sum[k].expo=p1[i].expo;
            } 
       else if(p1[i].expo>p2[j].expo){
           sum[k].coeff=p1[i].coeff;
           sum[k].expo=p1[i].expo;
             }
       else if(p2[j].expo>p1[i].expo){
           sum[k].coeff=p2[j].coeff;
           sum[k].expo=p2[j].expo;
           }
   }
   printf("Sum:");
   for(k=0;k<n3;k++){
       if(sum[k].expo!=0){
           printf("%dx^%d+",sum[k].coeff,sum[k].expo);
       }
       else{
           printf("%d",sum[k].coeff);
       }
   }
     return 0;
}
