#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char URL[100];
    struct node *prev;
    struct node *next;
};

struct node* newPage(char *URL) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    strcpy(newNode->URL, URL);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void visitNewPage(struct node **current, char *URL) {
    struct node *newNode = newPage(URL);
    newNode->prev = *current;
    newNode->next = NULL;

    if (*current != NULL) {
        (*current)->next = newNode;
    }

    *current = newNode;
    printf("Visited: %s\n", URL);
}
void displayCurrentPage(struct node *current) {
    if (current != NULL) {
        printf("Current page: %s\n", current->URL);
    } else {
        printf("No pages visited yet.\n");
    }
}
void goBack(struct node **current) {
    if (*current != NULL && (*current)->prev != NULL) {
        *current = (*current)->prev;
        printf("Went back to: %s\n", (*current)->URL);
    } else {
        printf("No previous page.\n");
    }
}

void goForward(struct node **current) {
    if (*current != NULL && (*current)->next != NULL) {
        *current = (*current)->next;
        printf("Went forward to: %s\n", (*current)->URL);
    } else {
        printf("No forward page.\n");
    }
}

int main() {
    struct node *homepage = newPage("homepage.com");
    struct node *current = homepage;
    int ch;
    char url[100];

    while (1) {
        printf("\nMENU\n");
        printf("1. Visit new page\n");
        printf("2. Go back\n");
        printf("3. Go forward\n");
        printf("4. Display current page\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        getchar(); // consume leftover newline

        switch (ch) {
            case 1:
                printf("Enter URL: ");
                fgets(url, sizeof(url), stdin);
                url[strcspn(url, "\n")] = 0; // remove newline
                visitNewPage(&current, url);
                break;
            case 2:
                goBack(&current);
                break;
            case 3:
                goForward(&current);
                break;
            case 4:
                displayCurrentPage(current);
                break;
            case 5:
                printf("Exiting...\n");
                // Free all allocated nodes
                while (current->prev != NULL) {
                    current = current->prev;
                }
                while (current != NULL) {
                    struct node *next = current->next;
                    free(current);
                    current = next;
                }
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

