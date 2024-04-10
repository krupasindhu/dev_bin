#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define TRUE 1
#define FALSE 0

/* Linked list Info */
struct node {
    int data;
    struct node* next;
};

/*
 * @Function to create a list node
 * @Input: data
 * @Output: list node
 */
struct node* create_new_node(int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL) {
        printf("ERROR : MEMORY ALLOCATION failed while creating list node\n");
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* 
 * Linked list insertion - Insert from front
 * @Input:  Referance to list head & data
 * @output: VOID
 */
void insert(struct node** head_ref, int data) {
    struct node* new_node = create_new_node(data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/* 
 * Linked list display
 * @Input:  list head
 * @output: VOID
 */
void print_list(struct node* head) {
    /* make sure to use a temp variable don't traverse the head */
    struct node* temp = head;
    while(temp!=NULL) {
        printf ("%d \t",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* 
 * Linked list insertion - Insert at end of the list
 * @Input:  Referance to list head & data
 * @output: VOID
 */
void insert_at_end(struct node** head_ref, int data) {
    /* check head is valid or not */
    if(*head_ref == NULL) {
        printf("HEAD is NULL\n");
        return;
    }
    /*If list has only one elem */
    if((*head_ref)->next == NULL) {
        struct node* new_node = create_new_node(data);
        (*head_ref)->next = new_node;
        return;
    }
    /* create a new node */
    struct node* new_node = create_new_node(data);
    /* Traverse through the last elem and add a new node */
    struct node* temp = (*head_ref);
    while(temp->next != NULL) {
        temp = temp->next;
    }
    /* Now temp points to last node */
    temp->next = new_node;
}

/* 
 * Get the middle of the linked list
 * @Input:  Linked list head
 * @output: data at middle node
 */
int middle_of_the_linkedlist(struct node* head) {
    if(head == NULL) {
        printf("List is empty");
        return 0;
    }
    /* To get the middle of a linked list we need to use slow and fast ptr concept */
    struct node* slow_ptr = head;
    struct node* fast_ptr = head ;
 
    while(fast_ptr!=NULL && fast_ptr->next!=NULL) {
        /* Move the fast pointer by two nodes */
        fast_ptr = fast_ptr->next->next;
        /* Move slow pointer by one node*/
        slow_ptr = slow_ptr->next;
    }
    return slow_ptr->data;
}

/*
 * @Function to get the size of linked list
 */
int sizeoflinkedlist(struct node *head) {
    int count = 0;
    struct node *temp = head;
    while(temp!=NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

/*
 * @Function to insert a node to list at given position
 * @Input head ref, position , data
 * @return void
 */
void insert_at_pos(struct node **head_ref, int pos, int data) {

    /* check the position is valid or not */
    if(pos < 1 && pos > sizeoflinkedlist(*head_ref) + 1) {
        printf("Invalid position \n");
    } else {
        struct node* current = (*head_ref);
        /* Need to traverse till control reached the pos */
        for(int i = 1; i < pos-1; i++) {
            current = current->next;
        }
        /* Now current is points to prev elem of the pos */
        struct node* new_node = create_new_node(data);
        new_node->next = current->next;
        current->next = new_node;

        if(pos == 1) {
            (*head_ref) = current;
        }
    }
}

/*
 * @Function to delete a node from linked list
 * @Input head ref, position , data
 * @return void
 */
void delete(struct node **head_ref, int data)
{
    /* validate the head */
    if((*head_ref) == NULL) {
        printf("Linked List is Empty\n");
        return;
    }
    /* if the node to be deleted is a head node */
    struct node* temp = (*head_ref);
    if(data == (*head_ref)->data) {
        (*head_ref) = temp->next;
        free(temp);
        temp = NULL;
    } else {
        /* find the node to delete */
        struct node* temp = (*head_ref);
        struct node* temp1 = NULL;
        while(temp != NULL && temp->next != NULL ) {
            if(temp->next->data == data) {
                /* store the temp data */
                temp1 = temp->next;
                temp->next = temp1->next;
                free(temp1);
                temp1 = NULL;
                return;
            }
            temp = temp->next;
        }
    }

}

/*
 * @Function to reverse the linked list
 * @Input: referance to head
 * @Output: Void
 */
void reverse(struct node** head_ref) {
    struct node* prev = NULL;
    struct node* next = NULL;

    struct node* current = (*head_ref);

    while(current != NULL) {
        /* store the next */
        next = current->next;
        /* Reverse current node's pointer */
        current->next = prev;
        /* Move pointers one position ahead.*/
        prev = current;
        current = next;
    }
    (*head_ref) = prev;
}

/*
 * @Function to detect the lopp in a linked list
 * @Input: referance to head
 * @Output: struct node
 */
struct node* detectLoop(struct node* head) {

    if(head == NULL && head->next == NULL)
        return NULL;

    struct node *slow = head, *fast = head;

    while(fast != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            printf("Loop detected");
            break;
        }
    }
    /* If loop does not exist */
    if (slow != fast)
        return NULL;

   /* If loop exists. Start slow from */
   /* head and fast from meeting point.*/
    slow = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main()
{
    struct node* head = NULL;
    insert(&head, 10);
    insert(&head, 11);
    insert(&head, 12);
    insert(&head, 13);
    insert(&head, 14);
    insert(&head, 15);
    insert(&head, 16);
    insert(&head, 17);
    insert(&head, 18);
    insert(&head, 19);
    insert(&head, 20);
    print_list(head);
    insert_at_end(&head,100);
    insert_at_end(&head,200);
    print_list(head);
    printf("MiddleNode of the list:%d \n",middle_of_the_linkedlist(head));
    int pos = 4;
    printf("Size of the linked list :%d\n",sizeoflinkedlist(head));
    insert_at_pos(&head, pos, 111);
    printf("Size of the linked list :%d\n",sizeoflinkedlist(head));
    print_list(head);
    delete(&head, 12);
    print_list(head);
    delete(&head,20);
    print_list(head);
    delete(&head,200);
    print_list(head);
    reverse(&head);
    print_list(head);
     /* Create a loop for testing */
    head->next->next->next->next = head->next->next;
    struct node*result  = detectLoop(head);
    if(result != NULL) {
        printf("Starting point of the loop is %d", result->data);
    }
    return 0;
}