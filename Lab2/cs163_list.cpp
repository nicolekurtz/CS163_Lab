#include "cs163_list.h"
using namespace std;




//Implement these three functions
//Add to the end of the LLL as efficiently as possible
int list::add(journal_entry & to_add)
{
    if(!head)
    {
       head = new node;
       head->entry.copy_entry(to_add);
       tail = head;
       return 1;
    }

   tail->next = new node; 
   node * current = tail->next;
   current->entry.copy_entry(to_add);
   tail = current;
   return 1;
}

//Display all journal entries
//Return false if there are no entries
int list::display(void)
{
    if(head == NULL)
        return 0;
    //Your code goes here!
    node * current = head; 
    while(current)
    {
        current->entry.display();
        current = current->next;
    }
    return 1;

}

//Determine if there is a match with the title passed in
//and if so provide the matching journal entry back to the
//client program through the second argument.
//Return a zero if no match is found
int list::find(char matching_title[], journal_entry & found)
{
	//Your code goes here!           
    if(!head) return 0;

    return find(matching_title, found, head);
}

int list::find(char matching_title[], journal_entry & found, node * head)
{
    if(!head) return false;

    if(head->entry.retrieve(matching_title, found))
    {
        return true;
    }
    return find(matching_title, found, head->next);
}

//Copy the list passed in as an argument
//and add the nodes to the end of the current list
int list::append(list & source)
{
        //Your code goes here!
        if(!source.head) return 0;

        if(tail)
            this->tail->next = source.head;
        else
        {
            head = tail = source.head;
        }
        return 1;

}
