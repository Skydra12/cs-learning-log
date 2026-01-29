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
      printf("%d -> ", curr->data);
      curr = curr->next;
    }
    printf("NULL\n");
  }
  ```
  **Traversing is a process for print all values, search a specific value, find the length, find the place where the node is deleted or inserted, and find the sum or average.**
