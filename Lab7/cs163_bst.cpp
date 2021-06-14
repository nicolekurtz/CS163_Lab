#include "cs163_bst.h"
using namespace std;

// ***These are sample wrapper functions
table::~table()
{
     remove_all(root); //call the recursive removal_all private function
}

// This is a wrapper function that will call the recursive count function
int table::count()
{
    //Notice how the returned value from the recursive function is used
    return count(root);
}

// Now it is your turn to write the count function recursively
int table::count (node * root)
{
    int counter = 0;
    if(!root) return 0;

    if(!root->left && !root->right) 
        ++counter;

    counter = count(root->left);
    counter += count(root->right);
    
    return counter;
}


// Start with the wrapper function that calls the recursive function
int table::sum()
{
    //Call the recursive function here:
    return sum(root);

}

// Now it is your turn to write the sum function recursively
int table::sum (node * root)
{
    int result = 0;

    if(!root) return 0;

    result = sum(root->left) + root->data;
    result += sum(root->right) + root->data;
    return result;
}


int table::height()   //simply call the private version of the functions
{
    return height(root);
}

//Now write this function recursively
int table::height (node * root)
{
    //Call the recursive function here:
    if(!root) return 0;

    int left = height(root->left) + 1;
    int right = height(root->right) + 1;

    return max(left, right);
}

/*
int table::remove_all()
{
    //Call the recursive function here:
    if(!root) return 0;

    return remove_all(root);

}
*/

// Now it is your turn to write the remove_all function recursively
int table::remove_all(node * & root)
{
    if(!root) return 0;

    int result = remove_all(root->left) + 1;
    result  += remove_all(root->right) + 1;
    delete root;
    root = NULL;
    return result;
}  


int table::copy(const table & to_copy)
{
    //Call the recursive function here:

    return copy(root, to_copy.root);

}

// Now it is your turn to write the copy function recursively
int table::copy(node * & dest_root, node * source_root) 
{
    if(!source_root) return 0;

    dest_root = new node;
    dest_root->data = source_root->data;
    dest_root->right = dest_root->left = NULL;

    int result = copy(dest_root->left, source_root->left) +1;


    result += copy(dest_root->right, source_root->right);
    
    return result;

}  
