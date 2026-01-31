# Linked Lists in C

## Linked List
A dynamic data structure where each node contains data and a pointer to the next node

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
  
  if (head == NULL || second == NULL || third == NULL) return;

  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  printf("%d -> %d -> %d -> NULL\n", head->data, head->next->data, head->next->next->data); // 1 -> 2 -> 3 -> NULL

  free(third);
  free(second);
  free(head); // free the entire list that is no longer needed
  ```


- Traversing a Linked List
  ```C
  void printList(struct Node* head) {
    struct Node* curr = head;

    while(curr != NULL) {
      printf("%d -> ", curr->data); // visit the node
      curr = curr->next; // move to the next node
    }
    printf("NULL\n");
  }
  ```
   **Traversing is the process of visiting each node in the list. It is used to print values, search for a specific value, find the length of the list, and locate positions for insertion or deletion.**

- Inserting Nodes
  - Insert at beginning
    ```C
    void insertFront(struct Node** head, int value) { // since the function need to modify the head pointer itself, use **
      struct Node* newNode = malloc(sizeof(struct Node));
      if (newNode == NULL) return; // if allocation fails, exit the function
      
      newNode->data = value; // store the given value in the new node
      newNode->next = *head; // make the new node point to the current head node
      *head = newNode; // update the head pointer to point to the new node
    }
    ```
  - Insert at end
    ```C
    void insertEnd(struct Node** head, int value) {
      struct Node* newNode = malloc(sizeof(struct Node));
      if (newNode == NULL) return;
      
      newNode->data = value; // store the given value
      newNode->next = NULL; // this node will be the last node

      if (*head == NULL) { // if the list is empty
        *head = newNode; // the new node becomes the head
        return;
      }

      struct Node* curr = *head; // start traversing from the head
      while(curr->next != NULL) { // traverse until reach the last node
        curr = curr->next; 
      }

      curr->next = newNode; // link the last node to the new node
    }
    ```
- Deleting a Node
  ```C
  void deleteNode(struct Node** head, int value) { // since deleting the head requires updating the head pointer, use **
    if (*head == NULL) return;
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
## Memory Management Note
All dynamically allocated nodes should be freed using 'free()' to avaoid memory leaks. especially when nodes are deleted or when the entire list is no longer needed

## Time Complexity Summary
- Traversing: O(n)
- Insert at beginning: O(1)
- Insert at end: O(n)
- Deletion(by value): O(n)
