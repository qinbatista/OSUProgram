struct Myarray
{
    void *data;
};
struct Myarray* dynarray_create();
void dynarray_free(struct Myarray* this_arrary);
void dynarray_size();
void dynarray_insert();
void dynarray_remove();
void dynarray_get();
void dynarray_set();
void test_input();