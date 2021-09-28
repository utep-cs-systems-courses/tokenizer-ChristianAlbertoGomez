#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/*First we initialize the linkedlist.*/

List* init_history()
{
  List* new_list = (List*)malloc(sizeof(List*));
  new_list->root = malloc(sizeof(Item));
  return new_list;
}

/*Now we have to create a new method where we add a history item to the end.*/
void add_history(List *list,char *str)
{
  Item* current;
  int id_position=0;
  current = list -> root;
  if (list->root == NULL){
      list-> root = (Item*)malloc(sizeof(Item));
      list-> root -> id = id_position++;
      list-> root -> str = str;
      list-> root-> next = NULL;
    }
  else{
    while (current->next != NULL){
      current = current->next;
    }
      current->next = (Item*)malloc(sizeof(Item));
      current->next->id = id_position;
      current->next->str = str;
      current->next->next = NULL;
  }
}//add_history end

char *get_history(List *list, int id)
{
  Item* current = list->root->next;

  while (current != NULL){
    if (current->id == id){
      return current->str;
    }
    current = current->next;
  }
}

void print_history(List *list)
{
  Item *node = list->root->next;

  while (node != NULL) {
    printf("Entry:%d %s\n", node->id, node->str);
    node = node->next;
  }
}

void free_history(List *list)
{
  //Need to free each node and then free all the linkedlist.
  Item *currentNode;

  while(list->root!=NULL){
    if(list->root==NULL){
      continue;
    }
    currentNode = list->root; //current node works as a temp variable.
    list->root->next;
    free(currentNode->str); //We free the stored string in the current node.
    free(currentNode); //We free the node, just in case.
  }
  //Once we "free" the contents of nodes then we have to free the linkedlist.
  free(list);
}
