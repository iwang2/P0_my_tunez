struct node {
  char song[256];
  char artist[256];
  struct node *next;
};

struct node * insert_front(struct node *n, char s[256], char a[256]);

void print_list(struct node *head);

struct node * find_song(char *s);

struct node * find_artist(char *a);

// pointer to random element in list
struct node * random(struct node *head);

// probably should free and return the removed node
struct node * remove(struct node *n);

struct node * free_list(struct node *n);
