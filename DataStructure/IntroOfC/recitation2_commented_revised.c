#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// based on my comments you will want to #include <string.h> as well
struct pokemon
{
    char* name;
    int dex_num;
};
struct pokemon* create_poke_array(int num_poke);
void init_poke(struct pokemon* poke_array, int index, char* poke_name, int poke_dex_num);
struct pokemon * search_dex_num(struct pokemon * poke_array, int num_poke, int poke_dex_num);
struct pokemon * search_name(struct pokemon * poke_array, int num_poke, char* poke_name);
void print_poke(struct pokemon * poke);
void free_poke_array(struct pokemon* poke_array);

int main()
{
    struct pokemon* pokemon_array = create_poke_array(3);
    init_poke(pokemon_array,0,"name0",0);
    init_poke(pokemon_array,1,"name1",1);
    init_poke(pokemon_array,2,"name2",2);
    //counting array
    // struct pokemon* temp_pokemon_struct;
    // printf("this array:%zu\n",sizeof(*pokemon_array));
    // printf("this pokemon:%zu\n",sizeof(temp_pokemon_struct));

    // Here you are setting your array to be the result of the search
    // I think you meant
    // temp_pokemon_struct = search_name(arr, int, str)
    //but this can also be done as
    // print_poke(search_name(arr,int,str))
    // where searchXX() represents a call to either search function
    // but this way is incorrect because it oveerwrites the pointer to the pokemon array
    print_poke(search_dex_num(pokemon_array, 3, 0));
    print_poke(search_dex_num(pokemon_array, 3, 1));
    print_poke(search_dex_num(pokemon_array, 3, 3));
    print_poke(search_name(pokemon_array, 3, "name0"));
    print_poke(search_name(pokemon_array, 3, "name1"));
    print_poke(search_name(pokemon_array, 3, "name4"));
    free_poke_array(pokemon_array);
    return 0;
}
struct pokemon* create_poke_array(int num_poke)
{
    struct pokemon* bulba = malloc(num_poke * sizeof(struct pokemon));
    return bulba;
}
void init_poke(struct pokemon* poke_array, int index, char* poke_name, int poke_dex_num)
{
    poke_array[index].name = poke_name;
    poke_array[index].dex_num = poke_dex_num;
}
struct pokemon * search_dex_num(struct pokemon * poke_array, int num_poke, int poke_dex_num)
{
    /* This function is wrong
        What it should do is loop through the array and find the pokemon who's number matches
        Here is PSEUDOCODE that is not actual c code
        for pokemon in poke_arr
          if pokemon.dex_num = dex_num
            return x

        In this case you want to return a POINTER to the item which is done like this
        return &array[index]
        the & means return the address of this thing instead of the thing itself
    */
    for(int i = 0; i< num_poke; i++)
    {
        if(poke_array[i].dex_num == poke_dex_num)
            return &poke_array[i];
    }
    return NULL;
}

struct pokemon * search_name(struct pokemon * poke_array, int num_poke, char* poke_name)
{
    // this function is also wrong, for the same reasons as above
    // Additionally you cannot compare c style strings with the '=' or '==' signs because they are just arrays
    // Comparing 'str1==str2' is not comparing strings but their addresses. I can show you this directly in the debugger if you come to office hours
    // To compare strings use strcmp or strncmp
    // strncmp() is preferred
    // strncmp is called like strncmp(str1, str2, max number of charachters to compare)
    // in this case just set the third argument to 32 or 128
    // this function is weird as it returns 0 when the strings are equal, so your check for comparing strings must be
    // if ( ! strncmp(str1, str2, 128)) {
    // to work correctly
    for(int i = 0; i< num_poke; i++)
    {
        if(!strncmp(poke_array[i].name, poke_name,128))
        {
            return &poke_array[i];
        }
    }
    return NULL;
}
void free_poke_array(struct pokemon* poke_array)
{
    free(poke_array);
}

void print_poke(struct pokemon * poke)
{
    // please only print 1 pokemon here
    // The search function should return the ADDRESS of the found pokemon or NULL if it does not exist
    // In this print function you can use logic like
    // if (poke == NULL) {
    //   printf("that's extinct :(")
    // }
    // else {
    // print the pokemon
    // }
    printf("---------------------\n");
    if (poke == NULL) 
    {
      printf("that's extinct :(\n");
    }
    else
    {
        printf("name:%s\n",poke->name);
        printf("index:%d\n",poke->dex_num);
    }
}
