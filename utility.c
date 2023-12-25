#include "utility.h"
#include <stdlib.h>
#include <dirent.h>


void print_list(Node* root)
{
    printf("\nFiles Inside Your Directory :\n\n");
    while (root) {
        printf("%s\n", root -> data);
        root = root -> next;
    }
    printf("\n");
}


void deleteAll(struct Node** root)
{
    struct Node* iter = *root;
    struct Node* next;

    while (iter != NULL)
    {
        next = iter->next;
        free(iter);
        iter = next;
    }
    *root = NULL;
}


Node* insert_contiguous(Node* root, char sval[])
{
    if (root == NULL) {
        root = (Node*)malloc(sizeof(Node));
        strcpy(root->data, sval);
        root -> next = NULL;
        return root;
    }

    if (strcmp(root->data, sval) == 1) {
        Node* temp = (Node*)malloc(sizeof(Node));
        strcpy(temp-> data, sval);
        temp -> next = root;
        return temp;
    }

    Node* iter = root;

    while (iter -> next != NULL && strcmp(iter->next->data, sval) == -1) {
        iter = iter -> next;
    }

    Node* temp = (Node*)malloc(sizeof(Node));
    temp -> next = iter -> next;
    iter -> next = temp;
    strcpy(temp->data, sval);
    return root;
}


void compare(Node* root){
    int count = 0;
    while(root ->next != NULL && !strcmp(root->hash, root->next->hash)){
        count++;
        printf("%s had duplicated!\n",root->data);
        root = root->next;
    }
    printf("\n%d COUNTED!\n",count);
}


Node* control_files(Node* root) {
    char path[FILENAME_MAX];
    const char *p_dir_name = path;

    printf("Please enter directory of your folder:\n");
    scanf("%s", path);

    DIR* dir_path;
    struct dirent* file;
    dir_path = opendir(p_dir_name);

    if (!dir_path) {
        fprintf(stderr, "Folder not exist!");
        exit(EXIT_FAILURE);
    }

    while ((file = readdir(dir_path))) {
        root = insert_contiguous(root, file->d_name);
    }

    closedir(dir_path);

    return root;
}


void hash_control(Node* root)
{
    SHA256_CTX ctx;
    BYTE buffer[SHA256_BLOCK_SIZE];

    while(root != NULL){
        BYTE text[strlen(root->data)];
        memcpy(text,root->data,SHA256_BLOCK_SIZE);
        sha256_init(&ctx);
        sha256_update(&ctx, text, strlen(text));
        sha256_final(&ctx, buffer);

        for (int i = 0; i <SHA256_BLOCK_SIZE; ++i) {
            printf("%02x ", buffer[i]);
        }

        for (int j = 0; j <SHA256_BLOCK_SIZE; ++j) {
            memcpy(root->hash,buffer,SHA256_BLOCK_SIZE);
        }

        printf("\n");
        root = root -> next;
    }
}






