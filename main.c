#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "playlist.h"

int main(){
  struct node * head = (struct node *)malloc(sizeof(struct node));
  strcpy(head->song, "sweet caroline");
  strcpy(head->artist, "neil diamond");

  printf("original node\n");
  print_list(head);

  printf("TESTING FOR LIST FUNCTIONS========================\n\n");
  
  printf("insert_ordered------------------------------------\n");
  printf("-->  inserting chandelier and hallelujah\n");
  head = insert_ordered(head, "chandelier", "sia");
  print_list(head);
  
  head = insert_ordered(head, "hallelujah", "pentatonix");
  print_list(head);

  printf("insert_front--------------------------------------\n");
  printf("-->  inserting rolling in the deep\n");
  head = insert_front(head, "rolling in the deep", "adele");
  print_list(head);

  printf("find_song-----------------------------------------\n");
  printf("-->  finding chandelier\n");
  struct node * find = find_song(head, "chandelier", "sia");
  print_list(find);

  printf("find_artist---------------------------------------\n");
  printf("-->  finding neil diamond\n");
  find = find_artist(head, "neil diamond");
  print_list(find);

  printf("length--------------------------------------------\n");
  printf("length of list: %d\n\n", length(head));

  printf("random_node---------------------------------------\n");
  struct node * random = random_node(head);
  print_list(random);

  printf("remove_node---------------------------------------\n");
  printf("-->  removing random node given above\n");
  head = remove_node(head, random);
  print_list(head);

  /*
  free_list(head);
  print_list(head);
  */

  printf("\nTESTING PLAYLIST FUNCTIONS=======================\n\n");

  struct node * thing[26];
  int i;
  for(i = 0; i < 26; i++){
    thing[i] = (struct node *)malloc(sizeof(struct node));
  }
  add(thing, "rolling in the deep", "adele");
  print_all(thing);
}
