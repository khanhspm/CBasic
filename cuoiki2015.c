#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char ta[20];
    char tv[20];
    struct node *left, *right;
};

// Thêm từ
struct node* Themtu(struct node *root, char ta[], char tv[]){
    if(root == NULL){
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        strcpy(temp->ta, ta);
        strcpy(temp->tv, tv);
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    if(strcmp(ta, root->ta) < 0){
        root->left = Themtu(root->left, ta, tv);
    }else{
        root->right = Themtu(root->right, ta, tv);
    }
    return root;
}

// Hiển thị toàn bộ dữ liệu
void Hienthi(struct node *root){
    if(root == NULL) return;
    Hienthi(root->left);
    printf("%s\t\t\t%s\n", root->ta, root->tv);
    Hienthi(root->right);
}

// Tách chuỗi
void tachchuoi(char s[], char *p){
    p = strtok(s, " ");
    printf("%s\n", p);
    while(p != NULL){
        p = strtok(NULL, " ");
        if(p != NULL){
            printf("%s\n", p);
        }
    }
}

// Ghi lại File
void ghi_lai_file(struct node *root, FILE *fp){
    if(root == NULL){
        return;
    }
    fprintf(fp,"%s\t%s\n", root->ta, root->tv);
    ghi_lai_file(root->left, fp);
    ghi_lai_file(root->right, fp);
}

void main(){
    int lua_chon;
    struct node *root = NULL;
    FILE *fp1, *fp2;
    char TA[20];
    char TV[20];
    int t1, t2;

    // Đọc File
    fp1 = fopen("TudienAnh-Viet.txt", "r");
    if(fp1==NULL) exit(1);
    do{
        fscanf(fp1, "%s", TA);
        t1 = fgetc(fp1);
        fgets(TV, 20, fp1);
        if(feof(fp1)) break;
        // Tạo cây
        root = Themtu(root, TA, TV);
    }while(!feof(fp1));

    do{
        printf("--------------------------Menu------------------------------\n");
        printf("1. Hien thi toan bo du lieu\n");
        printf("2. Dich Anh-Viet\n");
        printf("3. Thoat\n");
        printf("------------------------------------------------------------\n\n");
        printf("Ban chon: ");
        scanf("%d", &lua_chon);
        switch(lua_chon){
            case 1:{
                Hienthi(root);
                break;
            }
            case 2:{
                char s[1000];
                char *p;
                printf("Nhap cau can dich: ");
                fflush(stdin);
                gets(s);
                strlwr(s); // Chuyển về dạng chữ thường
                tachchuoi(s, p);
            }
            case 3:{
                int xoa_file = remove("TudienAnh-Viet.txt");
                if(xoa_file == 0){
                    fp2 = fopen("TudienAnh-Viet.txt", "w");
                    ghi_lai_file(root, fp2);
                    fclose(fp2);
                }
                break;
                exit(1);
            }
        }
    }while(lua_chon != 3);
}