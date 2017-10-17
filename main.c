#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node * next; };

struct node * arr[26];

int main(){
  int a;
  for(a = 0; a < 26; a++){
    arr[a] = (struct node *)malloc(sizeof(struct node));
    arr[a]->i = a; 
  }
  return 0;
}
