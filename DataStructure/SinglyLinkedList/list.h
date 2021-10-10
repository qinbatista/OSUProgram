struct link
{
    void *data;
    struct link *next;
};
struct list
{
    struct link* head;
    int size;
    int capacity;
};
struct list* list_create();
void list_free();
void list_insert();
void list_remove();
void list_position();
void list_reverse();