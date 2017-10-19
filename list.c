#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "list.h"

// insert song_nodes in the front
struct node * insert_front(struct node *n, char *s, char *a){
  struct node * new = (struct node *)malloc(sizeof(struct node));

  strcpy(new->song, s);
  strcpy(new->artist, a);
  new->next = n;

  return new;
}

// insert song node in correct order
// returns head node
struct node * insert_ordered(struct node *n, char *s, char *a){
  
  struct node * insert = (struct node *)malloc(sizeof(struct node));
  strcpy(insert->song, s);
  strcpy(insert->artist, a);

  if(!n){
    return insert;
  }
  
  if(strcmp(a, n->artist) < 0
     ||
     (strcmp(a, n->artist) == 0 && strcmp(s, n->song) < 0)){
    insert->next = n;
    return insert;
  }
  
  struct node * head = n;
  struct node * before = (struct node *)malloc(sizeof(struct node));
  
  while(n && (strcmp(a, n->artist) > 0 ||
	      (strcmp(a, n->artist) == 0 && strcmp(s, n->song) > 0))){
    before = n;
    n = n->next;
  }

  before->next = insert;
  insert->next = n;
  
  return head;
}

// print entire list
void print_list(struct node *head){
  while(head){
    printf("%s: %s\n", head->artist, head->song);
    head = head->next;
  }
  printf("\n");
}

// find and return pointer to an individual song
struct node * find_song(struct node *n, char *s, char *a){
  while(n && (strcmp(n->artist, a) != 0 || strcmp(n->song, s) != 0)){
    n = n->next;
  }
  return n;
}

// find and return pointer to first song of an artist
struct node * find_artist(struct node *n, char *a){
  while(n && strcmp(n->artist, a) != 0){
    n = n->next;
  }
  return n;
}

// length
int length(struct node *n) {
  int len = 0;
  while (n) {
    len++;
    n = n->next;
  }
  return len;
}

// pointer to random element in list
struct node * random_node(struct node *head){
  srand(time(NULL));
  /*
  int i = rand() * length(head);
  */
  int i = rand() / (RAND_MAX / length(head) + 1);
  while (i) {
    head = head->next;
    i--;
  }
  return head;
}

// remove single node from the list
struct node * remove_node(struct node *head, struct node *n){
  struct node *temp;
  if(head == n){
    temp = head->next;
    free(head);
    return temp;
  }
  
  struct node *hold = head;
  while(head != n){
    temp = head;
    head = head->next;
  }
  if(!n->next){
    temp->next = NULL;
    free(n);
  }else{
    temp->next = n->next;
    free(n);
  }
  return hold;
}

// free entire list
void free_list(struct node *n){
  struct node * temp;
  while(n){
    temp = n->next;
    free(n);
    n = temp;
  }
}
