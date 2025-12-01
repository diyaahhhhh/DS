#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct page{
    char url[50];
    struct page *prev;
    struct page *next;
};
struct page *createNode(char *url){
    struct page *newPage=(struct page*)malloc(sizeof(struct page));
    strcpy(newPage->url,url);
    newPage->prev=NULL;
    newPage->next=NULL;
    return newPage;
}
struct page *head=NULL;
struct page *current=NULL;
void visitPage(char *url){
    struct page *newPage=createNode(url);
    if(head==NULL){
        head=current=newPage;
        return;
        
    }
    struct page *temp=current->next;
    while(temp!=NULL){
        struct page *next=temp->next;
        free(temp);
        temp=next;
    }
    current->next=NULL;
    newPage->prev=current;
    current->next=newPage;
    current=newPage;
}
void goBack(){
    if(current!=NULL && current->prev!=NULL){
        current=current->prev;
        printf("Went back to:%s\n",current->url);
    }
    else{
        printf("No previous page.");
    }
}
void currentPage(){
    if(current==NULL){
        printf("No page visisted yet.\n");
    }
    else{
        printf("Currently at:%s\n",current->url);
    }
}
void goForward(){
    if(current!=NULL && current->next!=NULL){
        current=current->next;
        printf("Went forward to:%s\n");
    }
    else{
        printf("No forward page.");
    }
}
int main(){
    int ch;
    char url[50];
    while(1){
        printf("MENU\n1. Visit\n2. Go back\n3. Go forward\n4. Show current\n5. Exit\n");
        printf("Enter choice:");
        scanf("%d",&ch);
        if(ch==5){
            break;
        }
        switch(ch){
            case 1:
              printf("Enter url:");
              scanf("%s",url);
              visitPage(url);
              break;
            case 2:
              goBack();
              break;
            case 3:
              goForward();
              break;
            case 4:
              currentPage();
              break;
        }
    }
return 0;
}
