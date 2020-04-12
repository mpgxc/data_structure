#include <stdio.h>
#include <stdlib.h>

#define fifo_malloc(generic_ptr) \
    (generic_ptr *)malloc(sizeof(generic_ptr));

#define initialize_class(generic_ptr) ({         \
    generic_ptr *tmp = fifo_malloc(generic_ptr); \
    tmp->size_q = 0;                             \
    tmp->this_info = 0;                          \
    tmp->next = NULL;                            \
    tmp->push = &(fifo_push);                    \
    tmp->show = &(fifo_show);                    \
    tmp;                                         \
})

typedef struct self
{
    int this_info;
    int size_q;
    struct self *next;
    //Methods
    void (*push)(struct self *, const int);
    void (*show)(struct self *);
} generic_fifo;

void fifo_push(generic_fifo *self, const int info)
{
    generic_fifo *tmp = fifo_malloc(generic_fifo);

    tmp->this_info = info;
    tmp->size_q = self->size_q + 1;
    tmp->next = NULL;

    printf("%d\n", self->size_q);

    self->next = tmp;
}

void fifo_show(generic_fifo *self)
{
    if (self != NULL)
    {
        printf("%d\n", self->this_info);
        fifo_show(self->next);
    }
}

int main(int argc, char **argv)
{
    generic_fifo *ptr = initialize_class(generic_fifo);

    ptr->push(ptr, 1);
    ptr->push(ptr, 2);
    ptr->push(ptr, 3);
    ptr->push(ptr, 4);
    ptr->push(ptr, 5);

    ptr->show(ptr);

    return 0;
}