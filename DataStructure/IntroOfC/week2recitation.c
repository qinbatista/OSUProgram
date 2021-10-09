#include<stdio.h>
#include <stdlib.h> 
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
    struct pokemon* temp_pokemon_struct;
    pokemon_array = search_dex_num(pokemon_array, 0, 99);
    pokemon_array = search_name(pokemon_array, 2, "name2.1");
    print_poke(pokemon_array);
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
    poke_array[num_poke].dex_num = poke_dex_num;
    return poke_array;
}

struct pokemon * search_name(struct pokemon * poke_array, int num_poke, char* poke_name)
{
    poke_array[num_poke].name = poke_name;
    return poke_array;
}
void free_poke_array(struct pokemon* poke_array)
{
    free(poke_array);
}

void print_poke(struct pokemon * poke)
{
    printf("name:%s\n",poke[0].name);
    printf("index:%d\n",poke[0].dex_num);
    printf("-------\n");
    printf("name:%s\n",poke[1].name);
    printf("index:%d\n",poke[1].dex_num);
    printf("-------\n");
    printf("name:%s\n",poke[2].name);
    printf("index:%d\n",poke[3].dex_num);
}