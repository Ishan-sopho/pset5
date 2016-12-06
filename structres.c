typedef struct node
{
    char* word;
    struct node* next;
}node;

typedef struct trie
{
    struct trie [26];
    char letter;
    node* linker;
}