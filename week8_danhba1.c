#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
struct Item{
    char ten[20];
    char sdt[11];
    char email[30];
};
typedef struct Item item;

struct node{
    item key;
    struct node *Left, *Right;
};
typedef struct node Node;
typedef Node *Tree;

Node* makeNode(Node *p, item x){
    p = (Node*) malloc(sizeof(Node));
    p->key = x;
    p->Left = p->Right = NULL;
    return p;
}

Node* CreatTree(Node *p, itemx){
    printf("")
}