#include "cs163_bst.h"
using namespace std;

int main()
{
    table BST;	
    table tocopy;
    BST.build();
    BST.display();

    /*  PLACE YOUR FUNCTION CALL HERE */
    int result = 0;
    //result = BST.count();
    //result = BST.sum();
    //result = BST.height();
    //result = tocopy.copy(BST);
    cout << endl << "The result of this function is " << result << endl;


    BST.display();
    //tocopy.display();

    return 0;
}
