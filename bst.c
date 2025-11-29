#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createNode(int data){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->left=newNode->right=NULL;
    newNode->data=data;
    return newNode;
}
struct node *insert(struct node *root,int data){
    if(root==NULL){
        return createNode(data);
    }
    else if(data<root->data){
            root->left=insert(root->left,data);
            return root;
        }
    else if(data>root->data){
            root->right=insert(root->right,data);
            return root;
        }
}
struct node *search(struct node *root,int key){
    if(key==root->data){
        return root;
        printf("%d found\n",key);
    }
    else if(key<root->data){
        return root->left=search(root->left,key);
    }
    else {
        return root->right=search(root->right,key);
    }
}
struct node *findMin(struct node *root){
    while(root!=NULL){
        root=root->left;
    }
    return root;
}
struct node *delete(struct node *root,int key){
    if(root==NULL){
        return root;
    }
    if(key<root->data){
        root->left=delete(root->left,key);
    }
    else if(key>root->data){
        root->right=delete(root->right,key);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            free(root);
        }
        else if(root->left==NULL){
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node *temp=root->left;
            free(root);
            return temp;
        }
struct node *temp=findMin(root->right);
root->data=temp->data;
root->right=delete(root->right,temp->data);
}
return root;
}
void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
int main(){
    int n,num,ch,key;
    struct node *root=NULL;
    while(1){
    printf("MENU\n1. Insert\n2. Search\n3. Delete\n4. Traversal\n5. Exit\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    if(ch==1){
        printf("Enter the value:");
        scanf("%d",&num);
        root=insert(root,num);
        printf("Inserted\n");
    }
    else if(ch==2){
        printf("Enter key to be searched for:");
        scanf("%d",&key);
        search(root,key);
        printf("Found!\n");
    }
    else if(ch==3){
        printf("Enter key to be deletd:");
        scanf("%d",&key);
        delete(root,key);
        printf("Deleted.\n");
    }
    else if(ch==4){
        inorder(root);
    }
    else if(ch==5){
        break;
    }
}
return 0;
}
