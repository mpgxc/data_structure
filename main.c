#include <stdio.h>
#include <stdlib.h>

#define inlinetialize_fifo \
    NULL

#define fifo_malloc(generic_ptr) \
    (generic_ptr *)malloc(sizeof(generic_ptr))

typedef struct this
{
    int this_value;
    struct this *next;
}
fifo;

fifo *fifo_push(fifo *origin_fifo, int value)
{

    fifo *tmp = fifo_malloc(fifo);

    tmp->this_value = value;
    tmp->next = NULL;

    /*Caso não seja o primeiro Node da Fila*/
    if (origin_fifo != NULL)
    {
        printf("Opa2\n");
        /*Faz cópia da fila original*/
        fifo *cpy = origin_fifo;
        cpy->next = tmp;
        return cpy;
    }
    return tmp;
}

void fifo_show(fifo *origin_fifo)
{
    if (origin_fifo != NULL)
    {
        printf("%d\n", origin_fifo->this_value);

        fifo_show(origin_fifo->next);
    }
}

int main(int argc, char **argv)
{

    fifo *my_fifo = inlinetialize_fifo;

    my_fifo = fifo_push(my_fifo, 5);
    my_fifo = fifo_push(my_fifo, 10);

    fifo_show(my_fifo);
    return 0;
}
