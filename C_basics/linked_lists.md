# Linked Lists in C

## Linked List
A dynamic data structure where each element (node) points to the next one

## Structure of a Node
```C
struct Node {
  int data;
  struct Node* next;
};
```
## Example
- Creating 3 nodes
  ```C
  struct Node* head = malloc(sizeof(struct Node));
  struct Node* second = malloc(sizeof(struct Node));
  struct Node* third = malloc(sizeof(struct Node));

  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  printf("%d -> %d -> %d -> NULL\n", head->data, head->next->data, head->next->next->data); // 1 -> 2 -> 3 -> NULL
  ```


- Traversing a Linked List
  ```C
  void printlist(struct Node* head) {
    struct Node* curr = head;

    while(curr != NULL) {
      printf("%d -> ", curr->data); // visit the node
      curr = curr->next; // move to the next node
    }
    printf("NULL\n");
  }
  ```
   **Traversing is a process for print all values, search a specific value, find the length, find the place where the node is deleted or inserted, and find the sum or average.**

- Inserting Nodes
  - Insert at beginning (O(1))
    ```C
    void insertFront(struct Node** head, int value) { // since the function need to modify the head pointer itself, use **
      struct Node* newNode = malloc(sizeof(struct Node));
      newNode->data = value; // store the given value in the new node
      newNode->next = head; // make the new node point to the current head node
      *head = newNode; // update the head pointer to point to the new node
    }
    ```
  - Insert at end (O(n))
    ```C
    void insertEnd(struct Node* head, int value) {
      struct Node* newNode = malloc(sizeof(struct Node))
      newNode->data = value;
      newNode->next = NULL; // since this will be the last node, next is NULL

      while(head->next != NULL) { // traverse until reach the last node
        head = head->next; 
      }

      head->next = newNode; // link the last node to the new node
    }
    ```
- Deleting a Node
  ```C
  void deleteNode(struct Node** head, int value) { // since deleting the head requires updating the head pointer, use **
    struct Node* curr = *head; // start from the head of the list
    struct Node* prev = NULL; //prev will track the node before curr

    while (curr != NULL && curr->data != value) { // traverse the list until we find the value or reach the end(NULL)
      prev = curr; // move prev forward
      curr = curr->next; // move curr forward
    }

    if (curr == NULL) return; // if curr is NULL, the value was not found

    if (prev == NULL) { // if prev is NULL, delete the head node
      *head = curr->next; // move head to the next node
    } else { // otherwise, bypass the current node
      prev->next = curr->next;
    }

    free(curr); // free the memory of the deleted node
  }
  ```
