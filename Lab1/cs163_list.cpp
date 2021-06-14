#include "cs163_list.h"
using namespace std;

//Sum  all of the data together in a LLL
int list::sum_total()
{
 	//FIRST do this iteratively here. Then recursively
    //COMMENT out the iterative version when  rewriting
    //the solution recursively
    /*
    int total = 0;
    node * current = head;
    while(current)
    {
        total += current->data;
        current = current->next;
    }
    return total;
    */

        //To solve this recursively write another
        //function:   int sum_total(node * head);
        //and call it from this function
    return sum_total(head);

}

//Now implement the function recursively!
int list::sum_total(node * head)
{
    int result = 0;

    if(!head) return 0;

    result = sum_total(head->next) + head->data;
}

// *************************************************
//Remove the last node in a LLL. Return false if the
//list is empty and nothing is removed
bool list::remove_last()
{
        //Write your code here
 	//FIRST do this iteratively here. Then recursively
    // BUG EXAMPLE:

    node * current = head;
    node * prev;

    while(current->next)
    {
        prev = current;
        current = current->next;
    }

    delete current;
    current = NULL;
    current = prev;
    prev->next = NULL;
    /*
    //COMMENT out the iterative version when  rewriting
        
    if(!head) return false;

    return remove_last(head, tail);
    */
}

//Now implement the function recursively!
bool list::remove_last(node * & head, node * & tail)
{
    // BUG CODE:
    if(!head)
        return true;

    if(!head->next->next)
    {
        delete head->next;
        head->next = NULL;
    }

    return remove_last(head->next, tail);
}

// ************************************************
//Remove all nodes in a LLL. Remove false if there is
//nothing to remove
bool list::remove_all()
{
    //Remove all nodes in a LLL
 	//FIRST do this iteratively here. Then recursively
    /*
    if(!head) return false;

    node * current = head;
    node * prev = NULL;

    while(current)
    {
        prev = current;
        current = current->next;
        delete prev;
        prev = NULL;
    }

    head = tail = NULL;
    return true;
    */
    //COMMENT out the iterative version when  rewriting
    return remove_all(head);

}

//Now implement the function recursively!
bool list::remove_all(node * & head)
{
    if(!head) return 0;

    return remove_all(head->next) + 1;

    delete head;
    head = NULL;
}


// ************************************************
//Return true if the requested item (sent in as an argument)
//is in the list, otherwise return false
bool list::find_item(int item_to_find)
{
    /*
        //Write your code here
        node * current = head;
        while(current)
        {
            if(current->data == item_to_find)
                return true;
            current = current->next;
        }
        return false;
        */
        return find_item(head, item_to_find);

}

//Now implement the function recursively!
bool list::find_item(node * head, int item_to_find)
{
    if(!head) return false; 

    if(head->data == item_to_find)
        return true;

    return find_item(head->next, item_to_find);

}


// ************************************************
//Make a complete copy of a LLL
bool list::copy(list & from)
{
        //Write your code here
        if(!from.head)
            return false;
        return copy(head, tail, from.head); 

}

//Now implement the function recursively
bool list::copy(node * & dest_head, node * & dest_tail, node * source)
{
    if(!source)
        return true;

    dest_head = new node;
    dest_head->data = source->data;

    if(!source->next)
    {
        dest_tail = dest_head;
    }
    return copy(dest_head->next, dest_tail, source->next);

}
