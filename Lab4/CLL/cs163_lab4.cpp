#include "clist.h"

//Here is the main you will use for the circular linked list portion

int main()
{
    list object;
    object.build();		//builds a circular LL
    object.display();	 	//displays the list

    //PLEASE PUT YOUR CODE HERE to call the function being tested
    object.remove_entire();
    //cout << endl << "Ths count of this list is: " << object.count_all() << endl;


    object.display(); //resulting list after your function call!
    
    return 0;
}
