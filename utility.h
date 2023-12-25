//
#ifndef PROJECT_UTILITY_H
#define PROJECT_UTILITY_H


#include <stdio.h>
#include "sha256.h"


struct Node
{
    char data[FILENAME_MAX];
    char hash[SHA256_BLOCK_SIZE];
    struct Node* next;
};


typedef struct Node Node;

Node* insert_contiguous(Node* root, char sval[]);
Node* control_files(Node* root);

void print_list(Node* root);
void compare(Node* root);
void deleteAll(Node** root);
void hash_control(Node* root);



#endif //PROJECT_UTILITY_H
