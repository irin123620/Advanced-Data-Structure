#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

/* Insert at beginning */
void insert() {
    int value;
    struct node *newnode;

    printf("Enter a value to insert: ");
    scanf("%d", &value);

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    newnode->prev = NULL;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;
    printf("New node inserted\n");
}

/* Delete from beginning */
void delete() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
    printf("First node deleted\n");
}

/* Display forward */
void display() {
    struct node *temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Forward: NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Display backward */
void displayBackward() {
    struct node *temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Backward: NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

/* Search element */
void search() {
    struct node *temp = head;
    int key, pos = 1, found = 0;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter value to search: ");
    scanf("%d", &key);

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (!found)
        printf("Element %d not found in the list\n", key);
}

int main() {
    int choice;

    while (1) {
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Display Forward");
        printf("\n4.Display Backward");
        printf("\n5.Search");
        printf("\n6.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: displayBackward(); break;
            case 5: search(); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
