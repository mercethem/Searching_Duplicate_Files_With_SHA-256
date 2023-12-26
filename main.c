#include "utility.h"


int main()
{
    Node *root = NULL;
    root = control_files(root); //Check files and add inside list

    root = root->next->next; //It is use for just entry directory search

    print_name_list(root); //File names list printing
    hashing(root); //Hashing
    compare(root); //Compare Hashes
    deleteAll(&root); //Free all

    return 0;
}

