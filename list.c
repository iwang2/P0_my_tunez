#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

// insert song_nodes in the front
struct node * insert_front(struct node *n, char *s, char *a){
  struct node * new;
  new = (struct node *)malloc(sizeof(struct node));

  new->song = s;
  new->artist = a;
  new->next = n;

  return new;
}

struct node * insert_ordered(struct node *n, char *s, char *a){
  struct node * before;
  while(strcmp(n->artist, a) < 0 &&
	strcmp(n->song, s) < 0){
    before = n;
    n = n->next;
  }
  struct node * insert = (struct node *)malloc(sizeof(struct node));
  insert->song = s;
  insert->artist = a;

  before->next = insert;
  insert->next = n;
  return insert;
}

// print entire list
void print_list(struct node *head){
  while(head){
    printf("%s, %s\n", head->artist, head->song);
    head = head->next;
  }
}

// find and return pointer to an individual song
struct node * find_song(struct node *n, char *s){
  while(n->song != s){
    n = n->next;
  }
  return n;
}

// find and return pointer to first song of an artist
struct node * find_artist(struct node *n, char *a){
  while(n->artist != a){
    n = n->next;
  }
  return n;
}

// pointer to random element in list
struct node * random(struct node *head);

// remove single node from the list
struct node * remove(struct node *n, char *song){
}

// free entire list
struct node * free_list(struct node *n){
  struct node * temp;
  while(n){
    temp = n->next;
    free(n);
    n = temp;
  }
  return temp;
}
