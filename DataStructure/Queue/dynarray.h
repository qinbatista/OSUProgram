struct dynarray
{
    void **data;
    int size;
    int capacity;
};
struct dynarray* dynarray_create();
void dynarray_free(struct dynarray* da);
int dynarray_size(struct dynarray* da);
void dynarray_insert(struct dynarray* da, void* val);
void dynarray_remove(struct dynarray* da, int idx);
void* dynarray_get(struct dynarray* da, int idx);
void dynarray_set(struct dynarray* da, int idx, void *val);
struct dynarray* expand_dynarray(struct dynarray* array,int size);

void dynarray_print(struct dynarray* this_array);
void test_input();