#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/*First we initialize the linkedlist.*/

List* init_history()
{
  List* new_list = (List*)malloc(sizeof(List*)*300);
  return new_list;
}

/*Now we have to create a new method where we add a history item to the end.*/
void add_history(List *list,char *str)
{
  //First we create new memory space for the new coming item
  Item* add_item=(Item*)malloc(sizeof(Item)*300);
  add_item->str=str;

  //Check if the root of the list is null. If yes add item, if not add item to the next.
  if(list->root==NULL){
    add_item->id=1;
    list->root=add_item;
  }
  else{
    Item* history_item = list->root;
    add_item->id=1;

    //Use a while loop to navegate through the linkedlist
    while(history_item->next!=NULL){
      add_item->id++;
      history_item = history_item->next;
    }//while
    history_item->next=add_item;
    add_item->id++;
  }
}//add_history end

char *get_history(List *list, int id)
{
  //Delcare where we have to start.
  List a = *list;
  List* current = (List*)malloc(sizeof(List));
  current = &a;

  //Use a while loop to navegate through the linkedlist and find the item.
  while(current->root != NULL){
    if(current->root->id == id){
      return (current->root->str);
    }
    current->root = current->root->next;
  }//while
  return "NOT FOUND";
}

void print_history(List *list)
{
  while(list->root!=NULL){
    printf("History ID:%d-->String:%s\n",list->root->id,list->root->str);
    list->root = list->root->next;
  }
}

void free_history(List *list)
{
  free(list);
}
