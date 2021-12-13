#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 20

typedef struct phoneaddress_t{
    char name[20];
    char tel[20];
    char email[30];
} phoneaddress;

typedef struct NODE{
    phoneaddress key;
    struct NODE* left;
    struct NODE* right;
} Nodetype;
typedef struct NODE* TreeType;

void MakeNULLtree(TreeType *T){
    (*T) = NULL;
}

int Emptytree(TreeType T){
    return NULL; 
}

TreeType makeNode(Nodetype *p, phoneaddress x){
    p = (Nodetype*)malloc(sizeof(Nodetype));
    p->key = x;
    p->left = p->right = NULL;
    return p;
}

TreeType Search(char* email,TreeType Root){
    if(Root == NULL) return NULL;
    else if(strcmp(Root->key.email, email) == 0) return Root;
    else if(strcmp(Root->key.email, email) < 0) return Search(email, Root->right);
    else{
        return Search(email, Root->left);
    }
}

void InsertNode(phoneaddress x,TreeType *Root ){
    if (*Root == NULL){
        *Root=(Nodetype*) malloc(sizeof(Nodetype));
        (*Root)->key = x;
        (*Root)->left = NULL;
        (*Root)->right = NULL;
    }
    else if (strcmp(((*Root)->key).email, x.email) > 0){
        InsertNode(x, (*Root)->left);
    }
    else if (strcmp(((*Root)->key).email, x.email) > 0){
        InsertNode(x,(*Root)->right);
    }
}    



int main(){
    FILE *fp;
    phoneaddress phonearr[MAX];
    TreeType root;
    int i, n, irc;
    n = 10;
/*    if((fp = fopen("phonebook.dat", "rb")) == NULL){
        printf("Can not open phonebook.dat !\n");
        exit(1);
    }
    irc = fread(phonearr, sizeof(phoneaddress), n, fp);
    fclose(fp);
    */
    for(i = 0; i < n; i++){
        printf("Enter Name: ");
        fflush(stdin);
        gets(phonearr[i].name);
        printf("Enter Telephone number: ");
        gets(phonearr[i].tel);
        printf("Enter Email: ");
        gets(phonearr[i].email);
        InsertNode(phonearr[i], root);
    }
    return 0;
}