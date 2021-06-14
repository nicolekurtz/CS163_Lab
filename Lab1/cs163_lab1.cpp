#include "cs163_list.h"
using namespace std;

int main()
{
    
    //First try this out as is. Then start adding in your function calls!
    list my_list;
    list copy_to;
    my_list.build();
    my_list.display_all();

        
    //PLACE YOUR FUNCTION CALL HERE!
    //int result = my_list.remove_last();
    //cout << "The result of this function is " << result << endl;
    
    /*
    if(my_list.find_item(3))
        cout << "match!" << endl;
    else
        cout << "no match" << endl;
    */
    copy_to.copy(my_list);

    cout << "THIS IS A COPY: " << endl;
    copy_to.display_all();
    
    my_list.display_all();
    return 0;    
}
