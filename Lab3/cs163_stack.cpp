#include "cs163_stack.h"


//These are the functions you will be implementing
//for this lab, using a linear linked list of arrays
//as the data structure

//Add a new item to the top of stack
int stack::push(const journal_entry & to_add)
{
        //Implement the function here
        // 3 cases: 
        // - no head
        // - top_index is equal to our MAX size 
        // - add to array at top_index
        
        if(!head)
        {
            head = new node;
            head->entries = new journal_entry[MAX];
            head->entries[top_index].copy_entry(to_add);
            head->next = NULL;
        }
        // need to hold our current head, create a new node with array
        // set new node to head and point it to previous head
        // add entry
        if(top_index == MAX)
        {
            top_index = 0;
            node * temp = new node;
            temp->entries = new journal_entry[MAX];
            temp->entries[top_index].copy_entry(to_add);
            node * hold = head;
            head = temp;
            head->next = hold;
        }
        else
        {
            head->entries[top_index].copy_entry(to_add);
        }
        ++top_index;
        return 1;
}

//Remove the top of stack
int stack::pop (void)
{
    // CASES:
    // 1. List is empty, return false
    // 2. top_index is -1, need to delete array and delete node, set next to head, decrement
    // 3. otherwise decrement as usual
    if(!head) return 0;

    else if(top_index == 1)
    {
        node * hold = head->next;
        delete [] head->entries;
        delete head;
        head = hold;
        if(head)
            top_index = MAX;
        else
            top_index = 0;
    }
    else
        --top_index;

}

//Supply the journal at the top of stack back to the client
//Return 0 if there are no items
//top_index is one beyond where the top of stack is...
//with no items, top_index is zero
int stack::peek(journal_entry & found_at_top) const
{
        if(!head) return 0;

        found_at_top.copy_entry(head->entries[top_index - 1]);
        return 1;
}

