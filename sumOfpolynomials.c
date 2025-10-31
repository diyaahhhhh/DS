#include<stdio.h>
struct pol{
    int coeff;
    int deg;
}p1[10],p2[10],sum[10];

int main(){
    int i,j,k,n1,n2,n3;
    printf("Enter the no. of terms for 1st polynomial:");
    scanf("%d",&n1);
    printf("Enter coefficient & degree respectively:");
    for(i=0;i<n1;i++){
        scanf("%d%d",&p1[i].coeff,&p1[i].deg);
    }
    printf("Enter the no. of terms for 2nd polynomial:");
    scanf("%d",&n2);
    printf("Enter coefficient & degree respectively:");
    for(j=0;j<n2;j++){
        scanf("%d\t%d",&p2[j].coeff,&p2[j].deg);
    }
    n3=n1+n2;
    i=j=k=0;
    while(i<n1 && j<n2){
    if(p1[i].deg==p2[j].deg){
        sum[k].coeff=p1[i].coeff+p2[j].coeff;
        sum[k].deg=p1[i].deg;
        i++,j++,k++;  //degrees are same. So moving all three forward
    }
    else if(p1[i].deg<p2[j].deg){
        sum[k].coeff=p2[j].coeff;
        sum[k].deg=p2[j].deg;
        j++,k++;     //j is added to sum. Moving j & k forward
    }
    else { 
        if(p1[i].deg>p2[j].deg){
        sum[k].coeff=p1[i].coeff;
        sum[k].deg=p1[i].deg;
        i++,k++;  //i is added to sum. Moving i & k forward
               }
        }
    }
    while(i<n1){
        sum[k++]=p1[i++];   //remaining terms in p1, if any
    }
    while(j<n2){
        sum[k++]=p2[j++];    //remaining terms in p2, if any
    }
    n3=k;  //actual no. of terms in sum is k
    printf("Sum:\n");
    for(k=0;k<n3;k++){
       if(sum[k].deg!=0){
        printf("%dx^%d+",sum[k].coeff,sum[k].deg);
    }
    else {
    printf("%d",sum[k].coeff);
    }
}
return 0;
}
