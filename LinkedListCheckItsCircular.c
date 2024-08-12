#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct node* insert(struct node* head, int data) {
    struct node* new_node = create_node(data);
    new_node->next = head;
    head = new_node;
    return head;
}

void display_node(struct node* head) {
    struct node* temp = head;
    while(temp != NULL) {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int detect_circular(struct node* head) {
    if (head == NULL) return 0;

    struct node* slow = head;
    struct node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return 1; // List is circular
        }
    }

    return 0; // List is not circular
}

int main() {
    struct node* head = NULL;  // Initialize head to NULL
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);
    head = insert(head, 40);

    display_node(head);

    // Uncomment to make the list circular
    head->next->next->next->next = head;

    if (detect_circular(head)) {
        printf("List is circular\n");
    } else {
        printf("List is not circular\n");
    }

    return 0;
}