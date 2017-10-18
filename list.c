#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

// insert song_nodes in the front
struct node * insert_front(struct node *n, char *s, char *a){
  struct node * new = (struct node *)malloc(sizeof(struct node));

  new->song = s;
  new->artist = a;
  new->next = n;

  return new;
}

// insert song node in correct order
struct node * insert_ordered(struct node *n, char *s, char *a){
	if (!n) {
		return insert_front(n, s, a);
	}
  struct node * before;
  while(strcmp(n->artist, a) < 0 && strcmp(n->song, s) < 0){
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
    printf("%s: %s\n", head->artist, head->song);
    head = head->next;
  }
}

// find and return pointer to an individual song
struct node * find_song(struct node *n, char *s){
  while(n && strcmp(n->song, s)){
    n = n->next;
  }
  return n;
}

// find and return pointer to first song of an artist
struct node * find_artist(struct node *n, char *a){
  while(n && strcmp(n->artist, a)){
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
struct node * random(struct node *head){
	int i = rand() * lenth(head);
	while (i != 0) {
		head = head->next;		
		i--;	
	}
	return head;
}

// remove single node from the list
void remove(struct node *n, char *s){
    struct node * temp = n;
    while (n && strcmp(n->song, s)){ 
        temp = n;
        n = n->next;
    }
    temp -> next = n -> next;
    free(n);  
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
