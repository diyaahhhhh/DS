#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {
    char data;
    struct node *left;
    struct node *right;
};

/* Create a new tree node */
struct node* createNode(char ch) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = ch;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/* Check if character is operator */
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

/* Build tree from postfix expression */
struct node* buildTree(char postfix[]) {

    struct node* stack[100];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {

        char ch = postfix[i];

        if (isspace(ch)) continue;   // skip spaces if any

        /* If operand → push node */
        if (!isOperator(ch)) {
            stack[++top] = createNode(ch);
        }
        /* If operator → pop two nodes and make new node */
        else {
            struct node* right = stack[top--];
            struct node* left  = stack[top--];

            struct node* op = createNode(ch);
            op->left = left;
            op->right = right;

            stack[++top] = op;
        }
    }

    return stack[top];  // root of tree
}

/* PREORDER = PREFIX */
void preorder(struct node* root) {
    if (root == NULL) return;
    printf("%c", root->data);
    preorder(root->left);
    preorder(root->right);
}

/* POSTORDER = POSTFIX */
void postorder(struct node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c", root->data);
}

int main() {

    char postfix[100];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    struct node* root = buildTree(postfix);

    printf("Prefix  : ");
    preorder(root);
    printf("\n");

    printf("Infix   : ");
    inorder(root);
    printf("\n");

    printf("Postfix : ");
    postorder(root);
    printf("\n");

    return 0;
}
