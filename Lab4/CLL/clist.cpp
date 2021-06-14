#include "clist.h"

//Here are the funcitons that we will be writing in lab for CLL
int list::remove_entire()
{
    if(!rear)
        return 0;

    return remove_entire(rear->next);
}

int list::remove_entire(node * & rear)
{
    // Make sure to set this->rear to NULL
    
    if(!rear) return 0;

    if(rear == this->rear) 
    {
        delete rear;
        this->rear = NULL;
        return 1;
    }
    else
    {
        node * hold = rear->next;
        delete rear;
        rear = hold;
    }

    int result = remove_entire(rear) + 1;
    return result;
}

int list::count_all()
{
    return count_all(rear);
}

int list::count_all(node * rear)
{
    if(rear->next == this->rear)
        return 1;

    return count_all(rear->next) + 1;
}
