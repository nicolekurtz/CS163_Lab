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
    
    result += insert_before(head->next, to_add);

    if (head->data == 2)
    {
        node *add_me = new node;
        add_me->data = to_add;
        
        if (head->previous)
        {
            node *prev = head->previous;
            prev->next = add_me;
            add_me->previous = prev;
            add_me ->next = head;
            head->previous =add_me;
            if (head == this->head)
            {
                this->head = head->previous;
            }

            return 1;
        }
    }
}
        
/*
int list::insert_before(node * & head, int to_add)
{
    int result = 0;

    if(!head)
        return 0;
    if(head->data == 2)
    {
        // create the node
        node * temp = new node; 
        temp->data = to_add;
        node * hold = head->previous;

        temp->next = head;
        temp->previous = hold;
        head->previous = temp;

        if(hold)
            hold->next = temp;
        
        // if head is our head of list, we need to make temp head
        if(head == this->head)
        {
            this->head = temp;
        }

    }

    result += insert_before(head->next, to_add);

    return result;

}




int list::insert_before(node * & head, int to_add)
{
    int result = 0;

    if(!head)
        return 0;
    if(head->data == 2)
    {
        node * temp = new node; 
        temp->data = to_add;

        temp->next = head;
        temp->previous = head->previous;
        head->previous = temp;
        head = temp;

        if(head->next == this->head)
        {
            this->head = head;
        }

        ++result;
        result += insert_before(head->next->next, to_add);
    }
    else
        result += insert_before(head->next, to_add);
    return result;

}
*/
int list::display_last_two()
{

}

int list::display_last_two(node * head)
{

}

int list::remove_last_two()
{

}

int list::remove_last_two(node * & head)
{

}

     

