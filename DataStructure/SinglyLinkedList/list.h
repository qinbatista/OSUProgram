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
struct list* list_insert(struct list* _list, void *data);
struct list* list_remove(struct list* _list, void *data);
struct list* list_remove_index(struct list* _list, int _index);
int list_position(struct list* _list, void *data);
struct list* list_reverse(struct list* _list);
void list_print(struct list* _list);