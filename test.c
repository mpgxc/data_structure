#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    char *sname;
    unsigned short int id;
} struct_person;

//Aloca espaço de memória e define o valor passado por parâmetro
#define str_malloc(str) ({                                        \
    char *_tmp = (char *)malloc(sizeof(char) * (int)strlen(str)); \
    strcpy(_tmp, str);                                            \
    _tmp;                                                         \
})

#define struct_malloc(generic_ptr) \
    (generic_ptr *)malloc(sizeof(generic_ptr))

void struct_show()
{
}

void toString(struct_person *ptr)
{
    printf("Name: %s\n"
           "\tSub Name: %s\n"
           "\tId: %d\n",

           ptr->name,
           ptr->sname,
           ptr->id);
}

int main(int argc, char **argv)
{
    struct_person *ptr = struct_malloc(struct_person);

    ptr->name = str_malloc("Mateus");
    ptr->sname = str_malloc("Pinto Garcia");
    ptr->id = 100;

    toString(ptr);

    return 0;
}