// add songs
void add(struct node *library[26], char *song, char *artist);

// search for a song
struct node * search_song(struct node *library[26], char *artist, char *song);

// search for a song
struct node * search_song(struct node *library[26], char *song);

// search for an artist
struct node * search_artist(struct node *library[26], char *a);

// print out all entries under certain letter
void print_letter(struct node *library[26], char l);

// print out all songs of certain artist
void print_artist(struct node *library[26], char *artist);

// print entire library
void print_all(struct node *library[26]);

// print out series of randomly chosen songs
void shuffle(struct node *library[26]);

// delete a song
struct node * delete_song(struct node *library[26], char *song);

// delete all
struct node * delete_all(struct node * arr[26]);
