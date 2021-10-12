struct Myarray
{
    void *data;
    int size;
    int capacity_index;
};
struct Myarray* dynarray_create();
void dynarray_free(struct Myarray* this_array);
int dynarray_size(struct Myarray* this_array);
struct Myarray* dynarray_insert(struct Myarray* array, void* data);
void dynarray_remove(struct Myarray* array, int remove_index);
void* dynarray_get(struct Myarray* array, int index);
void dynarray_set(struct Myarray* array, int index, void *value);

void dynarray_print(struct Myarray* this_array);
void test_input();