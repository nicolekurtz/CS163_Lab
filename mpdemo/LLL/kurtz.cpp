// Nicole Kurtz
#include "list.h"

int add_head_tail(node * head)
{
    node * temp;
    return add_head_tail(head, temp);
}

int add_head_tail(node * head, node * temp)
{
    if(!head)
        return 0;
    
    head->data = 69;

    return add_head_tail(head->next, temp);
}

int display_list(node * head)
{
    if(!head) return 0;

    cout << head->data << "-";

    return display_list(head->next);
}
