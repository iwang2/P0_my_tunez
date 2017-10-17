struct node * add(char *s, char *a);

struct node * f_song(char *s);

// does this return the first song of the artist??? aka will it use "find_artist" from list.h??
struct node * f_artist(char *a);

void print_letter(char l);

void print_artist(char *s);

void print_all(struct node * arr[26]);

void shuffle(struct node * arr[26]);

struct node * delete_song(struct node *n);

struct node * delete_all(struct node * arr[26]);
