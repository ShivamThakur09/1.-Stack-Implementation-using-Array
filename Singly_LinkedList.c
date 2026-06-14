#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node;

node *create(int);
node *addbeg(node*);
node *insertmid(node*);
node *insertend(node*);
void Print(node*);

int main() {
    node *start = NULL;
    int n, choice;

    printf("--- SINGLY LINKED LIST CREATION ---\n");
    printf("Enter the number of initial nodes: ");
    scanf("%d", &n);
    start = create(n);
    printf("\nInitial List: ");
    Print(start);

    // Menu Loop
    while (1) {
        printf("\n--- INSERTION MENU ---\n");
        printf("1. Insert at Beginning 2. Insert in Middle (Specific Position) 3. Insert at End 4. Display List 5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting program...\n");
            break;
        }

        switch (choice) {
            case 1:
                start = addbeg(start);
                break;
            case 2:
                start = insertmid(start);
                break;
            case 3:
                start = insertend(start);
                break;
            case 4:
                printf("\nCurrent List: ");
                Print(start);
                break;
            default:
                printf("Invalid Choice! Please enter a number between 1 and 5.\n");
                break;
        }
    }
    return 0;
}

node *create(int n) {
    node *head = NULL, *p = NULL, *temp = NULL;
    int i;

    if (n <= 0) return NULL;
    head = (node*)malloc(sizeof(node));
    printf("Enter value for node 1: ");
    scanf("%d", &head->data);
    head->next = NULL;
    p = head;

    for (i = 2; i <= n; i++) {
        temp = (node*)malloc(sizeof(node));
        printf("Enter value for node %d: ", i);
        scanf("%d", &temp->data);
        temp->next = NULL;
        p->next = temp; // Link previous node to new node
        p = p->next;    // Move pointer forward
    }
    return head;
}

void Print(node *p) {
    if (p == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

node *addbeg(node *p) {
    node *tmp;
    int item;
    tmp = (node*)malloc(sizeof(node));
    printf("Enter the value to insert at FIRST position: ");
    scanf("%d", &item);
    tmp->data = item;
    tmp->next = p; // Point new node to the old head
    p = tmp;       // Make new node the head
    printf("%d inserted at the beginning.\n", item);
    return p;
}

node *insertend(node *head) {
    node *p, *q;
    int item;
    p = (node*)malloc(sizeof(node));
    printf("Enter the value to insert at LAST position: ");
    scanf("%d", &item);
    p->data = item;
    p->next = NULL;

    if (head == NULL) {
        printf("%d inserted. (List was empty)\n", item);
        return p;
    }

    q = head;
    while (q->next != NULL) {
        q = q->next;
    }
    q->next = p; // Link the last node to the new node 
    printf("%d inserted at the end.\n", item);
    return head;
}

node *insertmid(node *head) {
    node *p, *q;
    int item, i, loc;
    printf("Enter the position to insert AFTER (e.g., 1 to insert after 1st node): ");
    scanf("%d", &loc);
    printf("Enter the item value: ");
    scanf("%d", &item);
    p = (node*)malloc(sizeof(node));
    p->data = item;
    p->next = NULL;

    q = head;
    for (i = 1; i < loc; i++) {
        if (q != NULL) {
            q = q->next;
        }
    }
    if (q == NULL) {
        printf("Location is out of bounds! There are fewer elements than requested.\n");
        free(p); // Prevent memory leak
        return head;
    }
    p->next = q->next;
    q->next = p;
    printf("%d inserted successfully after position %d.\n", item, loc);
    return head;
}
