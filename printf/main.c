#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void *print(const char *str, ...)
{
    va_list args;

    va_start(args, str);
    vfprintf(stderr, str, args);

    va_end(args);
    fputc('\n', stderr);

    return NULL;
}

int main(int argc, char const *argv[])
{
    print("Opa %i %s", 6, "Deu certo!");
    return 0;
}
