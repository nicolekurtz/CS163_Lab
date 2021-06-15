#include "dlist.h"

//Now let's test doubly linked lists

int main()
{
    list object;
    object.build();
    object.display();

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    int to_add = 69;
    //cout << "The # of 2's is: " << object.insert_after(to_add) << endl;
    //cout << "The # of 2's is: " << object.insert_before(to_add) << endl;
    //cout << "Sum of last two: " << object.display_last_two() << endl;
    cout << "number of nodes after removal " << object.remove_last_two() << endl;


    object.display();
    
    return 0;
}
