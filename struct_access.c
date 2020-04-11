#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

typedef char *string;
typedef struct
{
    string *name;
    string *sname;
    unsigned short int id;
} struct_person;

#define tmp_buffer(length) ({                 \
    (string *)calloc(sizeof(string), length); \
})

//Aloca espaço de memória e define o valor passado por parâmetro
#define str_malloc(str) ({                                              \
    string *_tmp = (string *)malloc(sizeof(string) * (int)strlen(str)); \
    strcpy(_tmp, str);                                                  \
    _tmp;                                                               \
})

#define struct_malloc(generic_ptr) \
    (generic_ptr *)malloc(sizeof(generic_ptr))

static void alert(const string *fmt, ...)
{
    /*
        ... doing
    */
    va_list args;

    va_start(args, fmt);
    vfprintf(stderr, fmt, args);

    va_end(args);
    fputc('\n', stderr);

    exit(true);
}

string *toString(struct_person *ptr)
{
    string *buffer = tmp_buffer(255);
    sprintf(buffer, "Name:\t%s\nSName:\t%s\nId:\t%d\n",
            ptr->name, ptr->sname, ptr->id);

    return buffer;
}

int main(int argc, string **argv)
{
    struct_person *ptr = struct_malloc(struct_person);

    ptr->name = str_malloc("Mateus");
    ptr->sname = str_malloc("Pinto Garcia");
    ptr->id = 100;

    puts(toString(ptr));
    alert("Matando Processo: %d / %s %d Tests %s", 1, "Done", 2, "!");
    return 0;
}