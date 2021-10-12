#ifndef __DYNARRAY_H
#define __DYNARRAY_H
struct dynarray
{
    void *data;
    int size;
    int capacity_index;
};
struct dynarray* dynarray_create();
void dynarray_free(struct dynarray* this_array);
int dynarray_size(struct dynarray* this_array);
void dynarray_insert(struct dynarray* array, void* data);
void dynarray_remove(struct dynarray* array, int remove_index);
void* dynarray_get(struct dynarray* array, int index);
void dynarray_set(struct dynarray* array, int index, void *value);

void dynarray_print(struct dynarray* this_array);
void test_input();
#endif