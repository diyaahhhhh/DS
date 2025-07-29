#include <stdio.h>
int main(){
    int i,j,sr1=1,sr2=1,m1,n1,m2,n2,value1=0,S1[5][5],S2[5][5];
    printf("Enter row size and column sie of matrix A:");
    scanf("%d%d",&m1,&n1);
    int A[m1][n1];
    printf("Enter elements of matrix A:");
    for(i=0;i<m1;i++){
        for(j=0;j<n1;j++){
            scanf("%d",&A[i][j]);
            if(A[i][j]!=0){
            value1+=1;
        }
    }
    }
    
    printf("Input matrix A:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
           printf("%d\t",A[i][j]);
        }
    printf("\n");
    }
    printf("Non zero elements:%d\n",value1);
    S1[0][2]=3;
    for(i=0;i<m1;i++){
    for(j=0;j<n1;j++){
             if(A[i][j]!=0){
                S1[0][0]=i;
                S1[0][1]=j;
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
printf("Enter row size and column sie of matrix B:");
    scanf("%d%d",&m2,&n2);
    int B[m2][n2];
    printf("Enter elements of matrix B:");
    for(i=0;i<m2;i++){
        for(j=0;j<n2;j++){
            scanf("%d",&B[i][j]);
        }
    }
    printf("Input matrix B:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
           printf("%d\t",B[i][j]);
        }
    }
S2[0][2]=3;
    for(i=0;i<3;i++){
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
for(i=0;i<m2;i++){
    for(j=0;j<3;j++){
        printf("%d\t",S2[i][j]);
    }
    printf("\n");
}

return 0;
}

    
   
