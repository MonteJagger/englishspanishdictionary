//
//  main.c
//  algorithmsHW5
//
//  Created by Hiumathy Lam on 11/30/16.
//  Copyright © 2016 Hiumathy Lam. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
//#define arrSize 1000
//Definition of Node for Binary search tree
struct node {
    char *key; // english word
    char *value; // spanish word
    struct node* left;
    struct node* right;
};
// Function to create a new Node in heap
struct node* GetNewNode(char* key, char* value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->key = key;
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode; //return the address of the newly created node
}
// To insert data in BST, returns address of root node
struct node* Insert(struct node* root,char* key, char* value) {
    if(root == NULL) { // empty tree
        root = GetNewNode(key, value);
    }
    // if data to be inserted is lesser, insert in left subtree.
    else if(strcmp(key, root->key) <= 0) {
        //printf("left tree: %s  %s\n", key, root->key);
        root->left = Insert(root->left, key, value);
    }
    // else, insert in right subtree.
    else {
        //printf("right tree: %s  %s\n", key, root->key);
        root->right = Insert(root->right, key, value);
    }
    //printf("Address returned for %s: %p\n", key, root);
    return root;
}
//To search an element in BST, returns true if element is found
int Search(struct node* root, char* key) {
    if(root == NULL) {
        return 0;
    }
    else if(strcmp(key, root->key) == 0) {
        printf("%s\n", root->value);
        return 1;
    }
    else if(strcmp(key, root->key) <= 0) {
        return Search(root->left, key);
    }
    else {
        return Search(root->right, key);
    }
}
void reset_string(char* s, int max_len)      {
    int i;
    //printf("reset\n");
    for(i = 0; i < max_len-1; i++){
        s[i] = 'a';
    }
    s[max_len-1] = '0';
}
int main() {
    FILE *fp;
    
    printf("Two words\n");
    fp = fopen("Spanish.txt", "r");
    
    struct node* root = NULL;
    int c;
    
    
    while ((c = getc(fp)) != EOF) {
        char *first = (char*)malloc(1000*sizeof(char));
        char *second = (char*)malloc(1000*sizeof(char));
        fscanf(fp, "%s %[^\n]", first, second);
        
        if (first[0] == '#')
            continue;
        
        printf("%10s \t %40s\n", first, second);
        root = Insert(root, first, second);

    }
    
    char word[1000];
    
    while (word[0] != 'q'){
        printf("Enter word to be searched\n");
        scanf("%s", word);
        
        if (word[0] == 'q') continue;
        
        if (Search(root, word) == 1) printf("Found\n");
        else printf("Not found\n");
    }
}