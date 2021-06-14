#include "cs163_queue.h"


//Implement these functions using a Circular Linked List
//Add at the rear
int queue::enqueue(const journal_entry & to_add)
{
	//empty list
    if(!rear)
    {
        rear = new q_node;
        rear->entry.copy_entry(to_add);
        rear->next = rear;
        return 1;
    }

    q_node * hold = rear->next;
    rear->next = new q_node;
    rear->next->entry.copy_entry(to_add);
    rear = rear->next;
    rear->next = hold;
    return 1;
}

//Remove the node at the front
int queue::dequeue ()
{
    //conditions:
    //1. empty queue
    //2. one item in queue -- need to set rear to NULL
    //3. more than one item -- hold onto front-> next, set rear->next to front->next, delete front
    
    // empty list
    if(!rear) return 0;
    
    // one item in list
    if(rear->next == this->rear)
    {
        delete rear;
        rear = NULL;
        return 1;
    }
    
    // more than 1 items in list
    q_node * front = rear->next;
    rear->next = front->next;
    delete front;
    return 1;
}

