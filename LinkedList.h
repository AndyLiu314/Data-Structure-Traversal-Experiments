#ifndef LL_H
#define LL_H

#include <stdlib.h>
#include <stdio.h>

struct node {
	int data;
	struct node* next;
};
typedef struct node  node_t;

typedef struct {
	node_t* head;
} LL_t;

// Creates and returns a new, empty list
LL_t* LLcreate() {
    LL_t* ret = (LL_t*)malloc(sizeof(LL_t));
    if (ret == NULL)
        return NULL;
    
    ret->head = NULL;
    return ret;
}


// Adds a new element to the head  of a list
void LL_add_to_head(LL_t* list, int value) {
    node_t* newNode = (node_t*) malloc(sizeof(node_t));
    if (newNode == NULL) {
      printf("LL_add_to_head: malloc failed");
      return;
    }

    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
}

// Remove the element from the head of the list
int LL_remove_from_head(LL_t* list) {
  node_t* current_head = list->head;
  int ret = current_head->data;

  list->head = current_head->next;

  free(current_head);
  return ret;
}


// Prints the list elements in order from head to tail
void LL_print(LL_t* list) {
  node_t* current;

  for (current = list->head; current != NULL ; current = current->next )
    printf("%d ", current->data);
  printf("\n");
}

void LLnode_free(node_t* node) {
  free(node);
}

// releases the memore used by list
void LL_free(LL_t* list) {
  node_t* cur;
  while (list->head != NULL) {
    cur = list->head;
    list->head = cur->next;
    LLnode_free(cur); 
  }
  free(list);
}

#endif