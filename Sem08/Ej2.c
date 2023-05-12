#include <stdio.h>
#include <stdlib.h>


struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};


void insertFront(struct Node** head, int data) {
  
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

 
  newNode->data = data;

  newNode->next = (*head);

  newNode->prev = NULL;

  if ((*head) != NULL)
    (*head)->prev = newNode;

  (*head) = newNode;
}

void insertAfter(struct Node* prev_node, int data) {
  
  if (prev_node == NULL) {
    printf("Nodo previo no puede ser null");
    return;
  }

  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  newNode->data = data;

  newNode->next = prev_node->next;

  prev_node->next = newNode;

  newNode->prev = prev_node;

  if (newNode->next != NULL)
    newNode->next->prev = newNode;
}

void insertEnd(struct Node** head, int data) {

  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));


  newNode->data = data;

  newNode->next = NULL;


  struct Node* temp = *head;

  if (*head == NULL) {
    newNode->prev = NULL;
    *head = newNode;
    return;
  }

  while (temp->next != NULL)
    temp = temp->next;


  temp->next = newNode;


  newNode->prev = temp;
}

void deleteNode(struct Node** head, struct Node* del_node) {

  if (*head == NULL || del_node == NULL)
    return;

  if (*head == del_node)
    *head = del_node->next;


  if (del_node->next != NULL)
    del_node->next->prev = del_node->prev;


  if (del_node->prev != NULL)
    del_node->prev->next = del_node->next;


  free(del_node);
}

// imprimir la lista doblemente ligada
void displayList(struct Node* node) {
  struct Node* last;

  while (node != NULL) {
    printf("%d->", node->data);
    last = node;
    node = node->next;
  }
  if (node == NULL)
    printf("NULL\n");
}

int main() {
  // se inicializa un nodo vacío
  struct Node* head = NULL;

  insertEnd(&head, 5);
  insertFront(&head, 1);
  insertFront(&head, 6);
  insertEnd(&head, 9);

  // se inserta 11 después de cabeza
  insertAfter(head, 11);

  // se inserta 15 después del segundo nodo
  insertAfter(head->next, 15);

  displayList(head);

  // se borra el último nodo
  deleteNode(&head, head->next->next->next->next->next);

  displayList(head);
}