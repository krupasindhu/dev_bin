#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}Node;

Node* create_new_node(int data)
{
    Node* new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL) {
        printf("Memory Allocation Failled");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert(Node** head_ref, int data)
{
    Node* new_node = create_new_node(data);
    if (new_node == NULL) {
        printf("New node creation failed\n");
        return;
    }

    if (*head_ref == NULL) {
        // If the list is empty, make the new node the head
        *head_ref = new_node;
    } else {
        // Otherwise, insert at the beginning of the list
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
}
void display(Node* head)
{
    Node* temp = head; // Use a separate variable for iteration
    while(temp != NULL) {     // Use temp instead of head in the loop condition
        printf("Data:%d ", temp->data);
        temp = temp->next;    // Move to the next node
    }
    printf("\n");
}

Node* merge(Node* head1, Node* head2)
{
    Node* temp1;
    Node* temp2;
    temp1 = head1;
    temp2 = head2;
    // merge two linked list
    // create a dummy linked list.
    Node* dummy_node = create_new_node(-1);
    // points dummy node to one of the head
    Node* temp = dummy_node;
    while(temp1 != NULL && temp2 != NULL) { // check till the linked list is valid
        if(temp1->data > temp2->data){      // compare the data on t1 list and t2 list
            temp->next = temp1;             // if t1 data is higher linked the dummy node(temp) to t1
            temp = temp1;                   // move the popinter to t1 , now the temp is in list1
            temp1 = temp1->next;            // move on the list1
        } else {
            temp->next = temp2;
            temp = temp2;
            temp2 = temp2->next;
        }
    } // incase any elements leftout from list1 or list2
    if(temp1) {
        temp->next = temp1;
    }
    if(temp2) {
        temp->next = temp2;
    }
    return dummy_node->next;
}
int main()
{   // Driver code to verify linked list merge
    Node* head1 = NULL;
    insert(&head1, 10);
    insert(&head1, 30);
    insert(&head1, 50);
    insert(&head1, 70);
    insert(&head1, 90);
    printf("List 1\n");
    display(head1);

    Node* head2 = NULL;
    insert(&head2, 20);
    insert(&head2, 40);
    insert(&head2, 60);
    insert(&head2, 80);
    insert(&head2, 100);
    printf("List 2\n");
    display(head2);
    Node* res_node = merge(head1,head2);
    display(res_node);
    return 0;

}