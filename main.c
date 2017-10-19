#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

int main(){
  struct node * head = (struct node *)malloc(sizeof(struct node));
  strcpy(head->song, "sweet caroline");
  strcpy(head->artist, "neil diamond");

  print_list(head);

  head = insert_ordered(head, "chandelier", "sia");
  print_list(head);

  head = insert_front(head, "rolling in the deep", "adele");
  print_list(head);

  struct node * find = find_song(head, "chandelier", "sia");
  print_list(find);

  find = find_artist(head, "neil diamond");
  print_list(find);

  printf("length of list: %d\n", length(head));
  
  struct node * random = random_node(head);
  print_list(random);

  /*
  free_list(head);
  print_list(head);
  */
}
