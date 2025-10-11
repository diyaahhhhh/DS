#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct Node {
    char data;
    struct Node *left, *right;
};
char opStack[100];
struct Node* nodeStack[100];
int opTOP = -1;
int nodeTOP = -1;

void push(struct Node *node) {
    nodeStack[++nodeTOP] = node;
}
struct Node* pop() {
    return nodeStack[nodeTOP--];
}
int precedence(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}
struct Node* createNode(char c) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = c;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void infixToPostfix(char infix[], char postfix[]) {
    int j = 0;
    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            opStack[++opTOP] = c;
        } else if (c == ')') {
            while (opStack[opTOP] != '(') {
                postfix[j++] = opStack[opTOP--];
            }
            opTOP--;
        } else {
            while (opTOP != -1 && opStack[opTOP] != '(' &&
                   precedence(opStack[opTOP]) >= precedence(c)) {
                postfix[j++] = opStack[opTOP--];
            }
            opStack[++opTOP] = c;
        }
    }
    while (opTOP != -1) {
        postfix[j++] = opStack[opTOP--];
    }
    postfix[j] = '\0';
}
struct Node* buildTree(char postfix[]) {
    for (int i = 0; postfix[i]; i++) {
        char c = postfix[i];
        if (isalnum(c)) {
            push(createNode(c));
        } else {
            struct Node* right = pop();
            struct Node* left = pop();
            struct Node* opNode = createNode(c);
            opNode->left = left;
            opNode->right = right;
            push(opNode);
        }
    }
    return pop();
}
void preorder(struct Node* root) {
    if (root) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}
int main() {
    char infix[100], postfix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    struct Node* root = buildTree(postfix);
    printf("Prefix (preorder): ");
    preorder(root);
    printf("\n");
    printf("Postfix (postorder): ");
    postorder(root);
    printf("\n");
    return 0;
}
