#include "cs163_tree.h"
using namespace std;

int main()
{
    table trees;
    table copyto;
    trees.build();
    trees.display();

    /*  PLACE YOUR FUNCTION CALL HERE */
    //trees.display_largest();
    //cout << "The number of times root is in the tree is " << trees.count_root() << endl << endl;
    //copyto.copy(trees);
    //cout << " The number of 3 data items " << trees.count_3_data() << endl;
    //cout << "The height of the 234 tree is " << trees.height() << endl;
    cout << "nodes copied of 234 tree is " << copyto.copy_234(trees) << endl;
    
    copyto.display();
    return 0;
}
