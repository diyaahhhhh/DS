#include <stdio.h>
int main(){
    int i,j,sr1=1,sr2=1,m1,n1,m2,n2,value1=0,value2=0,S1[5][5],S2[5][5],SUM[5][5];
    printf("Enter row size and column sie of matrix A:");
    scanf("%d\t%d",&m1,&n1);
    int A[m1][n1];
    printf("Enter elements of matrix A:");
    for(i=0;i<m1;i++){
        for(j=0;j<n1;j++){
            scanf("%d",&A[i][j]);
                }
          }
    printf("Input matrix A:\n");
    for(i=0;i<m1;i++){
        for(j=0;j<n1;j++){
           printf("%d\t",A[i][j]);
           if(A[i][j]!=0){
               value1+=1;
           }
        }
    printf("\n");
    }
    S1[0][0]=value1+1;
    S1[0][1]=3;
    S1[0][2]=value1;
    for(i=0;i<m1;i++){
    for(j=0;j<n1;j++){
             if(A[i][j]!=0){
                S1[sr1][0]=i;
                S1[sr1][1]=j;
                S1[sr1][2]=A[i][j];
                sr1++;
             }  
        }
    }
printf("Sparse matrix of A:\n");
for(i=0;i<value1+1;i++){
    for(j=0;j<3;j++){
        printf("%d\t",S1[i][j]);
    }
    printf("\n");
}
printf("Enter row size and column size of matrix B:");
    scanf("%d\t%d",&m2,&n2);
    int B[m2][n2];
    printf("Enter elements of matrix B:");
    for(i=0;i<m2;i++){
        for(j=0;j<n2;j++){
            scanf("%d",&B[i][j]);
            if(B[i][j]!=0){
                value2+=1;
            }
        }
    }
    printf("Input matrix B:\n");
    for(i=0;i<m2;i++){
        for(j=0;j<n2;j++){
           printf("%d\t",B[i][j]);
        }
    printf("\n");
    }
S2[0][0]=value2+1;
S2[0][1]=3;
S2[0][2]=value2;
    for(i=0;i<value2+1;i++){
    for(j=0;j<3;j++){
             if(B[i][j]!=0){
                  S2[sr2][0]=i;
                  S2[sr2][1]=j;
                  S2[sr2][2]=B[i][j];
                  sr2++;
             }  
        }
    }
printf("Sparse matrix of B:\n");
for(i=0;i<value2+1;i++){
    for(j=0;j<3;j++){
        printf("%d\t",S2[i][j]);
    }
    printf("\n");
}
if(value1+1==value2+1){
    for(i=0;i<value1+1;i++){
       for(j=0;j<3;j++){
           SUM[i][j]=S1[i][j]+S2[i][j];
    }
  }
printf("Sum of sparse matrices:\n");
for(i=0;i<value1+1;i++){
       for(j=0;j<3;j++){
          printf("%d\t",SUM[i][j]);
    }
printf("\n");
   }
}

else{
    printf("Rows aren't same! Exiting...\n");
}
return 0;
}

    
   
