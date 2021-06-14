#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    add_head_tail(head);
    //display_list(head);


    display(head); //redisplay the list after your function
    //destroy(head); 
    return 0;
}
