#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "playlist.h"

// add songs
void add(struct node * library[26], char *s, char *a){
  int index = a[0] - 'a';
  library[index] = insert_ordered(library[index], s, a);
}

// search for a song
struct node * search_song(struct node *library[26], char *a, char *s){
  int i = a[0] - 'a';
  return find_song(library[i], s, a);
}

// search for an artist
struct node * search_artist(struct node *library[26], char *a){
  int index = a[0] - 'a';
  return find_artist(library[index], a);
}

// print out all entries under certain letter
void print_letter(struct node *library[26], char l){
  int index = l - 'a';
  print_list(library[index]);
}

// print out all songs of certain artist
void print_artist(struct node *library[26], char *a){
  print_list(search_artist(library, a));
  /*
  struct node * curr = find_artist(library, a);
  while (curr && !(strcmp(curr -> artist, a))) {
    printf("%s: %s\n", curr->artist, curr->song);
    curr = curr -> next;
  }
  */
}

// print entire library
void print_all(struct node * library[26]){
  for (int i = 0; i < 26; i++) {
    if (library[i]) {
      printf("library[%d]\n", i);
      print_list(library[i]);
    }
  }
}
/*
// print out series of randomly chosen songs
void shuffle(struct node *library[26]){
	
}
*/
// delete a song
void delete_song(struct node *library[26], char *a, char *s){
  int i = a[0] - 'a';
  library[i] = remove_node(library[i], search_song(library, a, s));
}

// delete all
void delete_all(struct node * library[26]){
  for (int i = 0; i < 26; i++) {
    free_list(library[i]);
    library[i] = NULL;
  }
}

