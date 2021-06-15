#include "dlist.h"

//Here are the functions you will be implementing for doubly linked lists
//

// insert a node after each two in the list
int list::insert_after(int to_add)
{
    return insert_after(head, to_add);
}

int list::insert_after(node * & head, int to_add)
{
    int result = 0;

    if(!head)
        return 0;
    if(head->data == 2)
    {
        node * hold = head->next;

        node * temp = new node; 
        temp->data = to_add;
        temp->next = hold;
        temp->previous = head;
        hold->previous = temp;
        head->next = temp;

        if(!temp->next)
        {
            this->tail = temp;
        }
    }
    else
        result += insert_after(head->next, to_add) + 1;
    return result;
}

int list::insert_before(int to_add)
{
    return insert_before(head, to_add);
}

int list::insert_before(node * & head, int to_add)
{
    int result;

    if (!head)
        return 0;
    
    if (head->data == 2)
    {
        node *add_me = new node;
        add_me->data = to_add;
        
        if (!(head == this->head))
        {
            node *prev = head->previous;
            add_me->previous = prev;
            add_me ->next = head;
            head->previous =add_me;
            prev->next = add_me;
            result += insert_before(head->next->next, to_add);
        }
        else
        {
            add_me->next = head;
            head->previous = add_me;
            this->head = add_me;
            result += insert_before(head->next->next, to_add);
        }
        ++result;
    }
    else
        result += insert_before(head->next, to_add);

}
        
int list::display_last_two()
{
    if(!head || !head->next)
        return 0;

    return display_last_two(head);
}

int list::display_last_two(node * head)
{
    int result = 0;

    if(!head) return 0;

    if(!head->next || !head->next->next)
    {
        result += head->data;
    }

    result += display_last_two(head->next);
    return result;

}

int list::remove_last_two()
{
    if(!head) return 0;

    return remove_last_two(head);
}

int list::remove_last_two(node * & head)
{
    if(!head) return 0;

    if(!head->next || !head->next->next)
    {
        if(!head->next)
        {
            node * temp = head->previous;
            delete head;
            head = temp;
            head->next = NULL;
            this->tail = head;
            return 0;
        }
        else
        {
            node * hold = head->next;
            hold->previous = head->previous;
            delete head;
            head = hold;
            return remove_last_two(head);
        }
    }
    else
        remove_last_two(head->next) + 1;

}

     

