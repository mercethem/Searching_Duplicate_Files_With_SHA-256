#include "utility.h"


int main()
{
    Node *root = NULL;
    root = control_files(root);

    root = root->next->next; //It is use for just entry directory search

    print_list(root); //File names list printing
    hash_control(root); //Hashing

    compare(root); //Compare Hashes
    deleteAll(&root); //Free all

    return 0;
}

