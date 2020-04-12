#include <stdio.h>
#include <stdlib.h>

#define linkedList_malloc(generic_ptr) \
    (generic_ptr *)malloc(sizeof(generic_ptr));

typedef struct self_node
{
    int this_info;
    struct self_node *next;
} Node;

typedef struct self_queue
{
    Node *head;
    unsigned short int size_q;

    //Methods
    void (*push_head)(struct self_queue *, const int);
    void (*push_rear)(struct self_queue *, const int);

    void (*show)(Node *);

} generic_linkedList;

void linkedList_push_rear(generic_linkedList *self, const int info)
{
}
void linkedList_push_head(generic_linkedList *self, const int info)
{
    Node *node_next = linkedList_malloc(Node);

    node_next->this_info = info;
    node_next->next = self->head;

    self->head = node_next;
    self->size_q += 1;
}

void linkedList_show(Node *self)
{
    if (self != NULL)
    {
        printf("%d\n", self->this_info);
        linkedList_show(self->next);
    }
}

generic_linkedList *initialize_linkedList()
{
    generic_linkedList *tmp = linkedList_malloc(generic_linkedList);

    tmp->head = NULL;
    tmp->size_q = 0;

    //Iniciando os métodos de acesso
    tmp->push_head = &linkedList_push_head;
    tmp->push_rear = &linkedList_push_rear;
    tmp->show = &linkedList_show;

    return tmp;
}

int main(int argc, char **argv)
{
    generic_linkedList *ptr = initialize_linkedList();

    ptr->push_head(ptr, 1);
    ptr->push_head(ptr, 2);
    ptr->push_head(ptr, 3);
    ptr->push_head(ptr, 4);
    ptr->push_head(ptr, 5);

    ptr->show(ptr->head);

    return 0;
}