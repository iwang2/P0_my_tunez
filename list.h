struct node {
  char song [256];
  char artist[256];
  struct node *next;
};

// insert song_nodes in the front
struct node * insert_front(struct node *n, char *s, char *a);

struct node * insert_ordered(struct node *n, char *s, char *a);

// print entire list
void print_list(struct node *head);

// find and return pointer to an individual song
struct node * find_song(struct node *n, char *s);

// find and return pointer to first song of an artist
struct node * find_artist(struct node *n, char *a);

// pointer to random element in list
struct node * random(struct node *head);

// remove single node from the list
struct node * remove(struct node *n, char *s);

// free entire list
struct node * free_list(struct node *n);
