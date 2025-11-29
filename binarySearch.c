#include <stdio.h>
int main() {
    int key,mid,low=0,n,num,i,flag=0,count=0;
    printf("Enter no. of elements:");
    scanf("%d",&n);
    count=n;
    int arr[n];
    printf("Enter elements in sorted way:");
    for(i=0;i<n;i++){
         scanf("%d",&arr[i]);
    }
    printf("Enter key to be searched for:");
    scanf("%d",&key);
    while(low<=count){
        mid=(low+count)/2;
        if(key==arr[mid]){
            printf("Element found in index %d\n",mid);
            flag=1;
            count++;
            break;
        }
        else if(key<arr[mid]){
            count=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    if(flag==0){
        printf("Element not found");
    }
    printf("Space complexity:%d bytes\n",sizeof(arr));
    printf("Time complexity:%d\n",count);
    return 0;
}
