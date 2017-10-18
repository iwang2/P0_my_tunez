#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

int main(){
  struct node * head = (struct node *)malloc(sizeof(struct node));
  strcpy(head->song, "sweet caroline");
  strcpy(head->artist, "neil diamond");

  print_list(head);

  head = insert_front(head, "chandelier", "sia");
  print_list(head);
  /*
  //insert_ordered does not insert in the correct order
  insert_ordered(head, "chandelier", "sia");

  print_list(head);
  */
}
