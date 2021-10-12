struct link
{
    void *data;
    struct link *next;
};
struct list
{
    struct link* head;
    int size;
};
struct list* list_create();
void list_free();
void list_insert(struct list* _list, void *data);
void list_remove(struct list* _list, void *data);
void list_remove_index(struct list* _list, int _index);
int list_position(struct list* _list, void *data);
void list_reverse(struct list* _list);
void list_print(struct list* _list);