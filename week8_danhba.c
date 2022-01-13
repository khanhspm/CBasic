#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char name[20];
    char email[25];
    char tel[12];
    struct node *left, *right;
};

// Thêm địa chỉ mới
struct node* insert(struct node *root, char name[], char email[], char tel[]){
    if(root == NULL){
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        strcpy(temp->name, name);
        strcpy(temp->email, email);
        strcpy(temp->tel, tel);
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    if(strcmp(email, root->email) <= 0){
        root->left = insert(root->left, name, email, tel);
    }else{
        root->right = insert(root->right, name, email, tel);
    }
    return root;
}

// Xuất tất cả địa chỉ ra màn hình
void Out(struct node *root){
    if(root == NULL){
        return;
    }
    Out(root->left);
    printf("%s\t %5s\t %5s\n", root->name, root->email, root->tel);
    Out(root->right);
}

// Tìm địa chỉ có email nhỏ nhất
struct node* FindMin(struct node *root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

// Xóa địa chỉ có email cần xóa
struct node* delete(struct node *root, char em[]){
    if(root == NULL){
        return root;
    }
    else if(strcmp(em, root->email) < 0){
        root->left = delete(root->left, em);
    }
    else if(strcmp(em, root->email) > 0){
        root->right = delete(root->right, em);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        else if(root->left == NULL){
            struct node *temp = root;
            root = root->right;
            free(temp);
            temp = NULL;
        }
        else if(root->right == NULL){
            struct node *temp = root;
            root = root->left;
            free(temp);
            temp = NULL;
        }
        else{
            struct node *temp = root;
            root->left = FindMin(root);
            root->left->right = root->right;
            root = root->left;
            strcpy(temp->name, root->name);
            strcpy(temp->email, root->email);
            strcpy(temp->tel, root->tel);
            free(temp);
            temp = NULL;
        }
        return root;
    }
    return root;
}

// Tìm kiếm địa chỉ có email cần tìm
void search(struct node *root, char em[]){
    if(strcmp(root->email, em) > 0){
        search(root->left, em);
    }
    else if(strcmp(root->email, em) < 0){
        search(root->right, em);
    }
    else{
        printf("%s\t %20s\t %12s\n", root->name, root->email, root->tel);
    }
}

void main(){
    struct node *root = NULL;
    int choose;
    char name[20], email[25], tel[12], email_search[25], email_delete[25];
    do{
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. List of book\n");
        printf("0. Out\n");
        printf("Your choice: ");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                   printf("Enter the name: ");
                   scanf("%s", &name);
                   printf("Enter the email: ");
                   scanf("%s", &email);
                   printf("Enter the telephone number: ");
                   scanf("%s", &tel);
                   root = insert(root, name, email, tel);
                   break;
            case 2:
                   printf("Enter the email need search: ");
                   scanf("%s", &email_search);
                   search(root, email_search);
                   break;
            case 3:
                   printf("Enter the email need delete: ");
                   scanf("%s", &email_delete);
                   delete(root, email_delete);
                   break;
            case 4: 
                   printf("%s\t %10s\t %20s\n", "Name", "Email", "Telephone number");
                   Out(root);
                   break;
            case 0:
                   exit(0);
                   break;
        }
    }while(1);
}