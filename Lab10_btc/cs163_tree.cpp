#include "cs163_tree.h"
using namespace std;



//These are the functions that you will be writing for the BST


void table::display_largest(){
    if(!root) return;
    return display_largest(root);
}      	

//STEP 1
void table::display_largest(node * root) {
    if(!root->right)
    {
        cout << endl<< "The largest data item is: " << root->data << endl << endl;
        return;
    }
    return display_largest(root->right);
}

int table::count_root()
{
    if(!root) return 0;
    int match = root->data;
    int result = count_root(root->left, match);
    result += count_root(root->right, match);
    return result;
}		

//STEP 2
int table::count_root(node * root, int match)
{
    if(!root) return 0;

    int result = count_root(root->left, match);

    if(root->data == match)
    {
        ++result;
    }

    result += count_root(root->right, match);
    return result;

}

void table::copy(table & source) {
    if(!source.root) return;

    copy(root, source.root);
}

void table::copy(node * & destination, node * source) 
{
    if(!source) return;

    destination = new node;
    destination->data = source->data;
    destination->right = destination->left = NULL;

    copy(destination->left, source->left);
    copy(destination->right, source->right);
}

//Now for the 2-3-4 Tree		//STEP 4
int table::count_3_data()   //sample wrapper function that return the count
{
      return count_3_data(root234);
}	     
     
int table::count_3_data(node234 * root){
    int result = 0;

    if(!root) return 0;

    if(root->data[0] && root->data[1] && root->data[2])
    {
        ++result;
    }
    
    for(int i = 0; i < 4; ++i)
        result += count_3_data(root->child[i]);

    return result;
}


//STEP 5
int table::height(){
    if(!root) return 0;

    return height(root234);
}                   

int table::height(node234 * root)
{
    if(!root) return 0;

    return height(root->child[0]) + 1;
}

//STEP 6
//Copy from the argument into the data members...
int table::copy_234(table & copy_from)
{
    if(!copy_from.root) return 0;

    return copy(root234, copy_from.root234);
}

int table::copy(node234 * & destination, node234 * source)
{
    int result = 0;
    if(!source) return 0;

    destination = new node234;
    for(int i = 0; i < 3; ++i)
    {
        destination->data[i] = source->data[i];
    }

    ++result;
    destination->child[0] = destination->child[1] = destination->child[2] = NULL;
    for(int i = 0; i < 4; ++i)
        result += copy(destination->child[i], source->child[i]);
    return result;
}

